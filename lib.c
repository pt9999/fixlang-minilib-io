#include <sys/types.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <signal.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int minilib_iofs_stat_or_lstat(const char* pathname, uint64_t *ret, int is_stat)
{
    struct stat st;
    int err;
    if (is_stat) {
        err = stat(pathname, &st);
    } else {
        err = lstat(pathname, &st);
    }
    if (err != 0) {
        return err;
    }
    ret[0] = (uint64_t)st.st_dev;
    ret[1] = (uint64_t)st.st_ino;
    ret[2] = (uint64_t)st.st_nlink;
    ret[3] = (uint64_t)st.st_mode;
    ret[4] = (uint64_t)st.st_uid;
    ret[5] = (uint64_t)st.st_gid;
    ret[6] = (uint64_t)st.st_rdev;
    ret[7] = (uint64_t)st.st_size;
    ret[8] = (uint64_t)st.st_blksize;
    ret[9] = (uint64_t)st.st_blocks;
#ifdef __APPLE__
    ret[10] = (uint64_t)st.st_atimespec.tv_sec;
    ret[11] = (uint64_t)st.st_atimespec.tv_nsec;
    ret[12] = (uint64_t)st.st_mtimespec.tv_sec;
    ret[13] = (uint64_t)st.st_mtimespec.tv_nsec;
    ret[14] = (uint64_t)st.st_ctimespec.tv_sec;
    ret[15] = (uint64_t)st.st_ctimespec.tv_nsec;
#else
    ret[10] = (uint64_t)st.st_atim.tv_sec;
    ret[11] = (uint64_t)st.st_atim.tv_nsec;
    ret[12] = (uint64_t)st.st_mtim.tv_sec;
    ret[13] = (uint64_t)st.st_mtim.tv_nsec;
    ret[14] = (uint64_t)st.st_ctim.tv_sec;
    ret[15] = (uint64_t)st.st_ctim.tv_nsec;
#endif
    return 0;
}

int minilib_iofs_stat_mode_is_file(uint32_t mode)
{
    return S_ISREG(mode) ? 1 : 0;
}

int minilib_iofs_stat_mode_is_dir(uint32_t mode)
{
    return S_ISDIR(mode) ? 1 : 0;
}

int minilib_iofs_stat_mode_is_symbolic_link(uint32_t mode)
{
    return S_ISLNK(mode) ? 1 : 0;
}

size_t minilib_iofs_readdir(void* dir_handle, uint8_t *buf, size_t bufsize)
{
    if (dir_handle == NULL || bufsize <= 0) {
        return 0;
    }
    struct dirent* dent = readdir((DIR*) dir_handle);
    if (dent == NULL) {
        // If the end of directory stream is reached or an error occurs, NULL is returned.
        // To distinguish an error or not, check `errno`.
        return 0;
    }

    size_t len = (size_t) strlen(dent->d_name);
    if (len >= bufsize) {
        len = bufsize;
    }
    memcpy(buf, dent->d_name, len);  // Copy to a byte array (not null-terminated)
    return len;
}

// Convert `whence` for portability
int minilib_iofs_convert_seek_whence(int whence)
{
    if (whence == 0) return SEEK_SET;
    if (whence == 1) return SEEK_CUR;
    if (whence == 2) return SEEK_END;
    return -1;
}

static char* _copy_str(char** p_buf, size_t* p_bufsize, char* src)
{
    size_t copy_size = strlen(src) + 1;
    if (copy_size > *p_bufsize) {
        *p_bufsize = 0;
        return NULL;
    }
    char* dest = *p_buf;
    strcpy(dest, src);
    *p_buf += copy_size;
    *p_bufsize -= copy_size;
    return dest;
}

int minilib_io_platform_uname(char *buf, size_t bufsize, char** out_names, size_t out_names_size)
{
    if (out_names_size < 5) {
        errno = EINVAL;
        return -1;
    }
    struct utsname uts;
    int err = uname(&uts);
    if (err != 0) {
        return -1;
    }
    out_names[0] = _copy_str(&buf, &bufsize, uts.sysname);
    out_names[1] = _copy_str(&buf, &bufsize, uts.nodename);
    out_names[2] = _copy_str(&buf, &bufsize, uts.release);
    out_names[3] = _copy_str(&buf, &bufsize, uts.version);
    out_names[4] = _copy_str(&buf, &bufsize, uts.machine);
    if (bufsize == 0) {
        errno = EMSGSIZE;   // Message too long
        return -1;
    }
    return 0;
}

struct signal_defs {
    const char* name;
    int signum;
} signal_defs[] = {
    { "SIGHUP", SIGHUP },
    { "SIGINT", SIGINT },
    { "SIGQUIT", SIGQUIT },
    { "SIGILL", SIGILL },
    { "SIGTRAP", SIGTRAP },
    { "SIGABRT", SIGABRT },
    { "SIGIOT", SIGIOT },
    { "SIGBUS", SIGBUS },
    { "SIGFPE", SIGFPE },
    { "SIGKILL", SIGKILL },
    { "SIGUSR1", SIGUSR1 },
    { "SIGSEGV", SIGSEGV },
    { "SIGUSR2", SIGUSR2 },
    { "SIGPIPE", SIGPIPE },
    { "SIGALRM", SIGALRM },
    { "SIGTERM", SIGTERM },
#ifdef SIGSTKFLT
    { "SIGSTKFLT", SIGSTKFLT },
#endif
    { "SIGCHLD", SIGCHLD },
    { "SIGCONT", SIGCONT },
    { "SIGSTOP", SIGSTOP },
    { "SIGTSTP", SIGTSTP },
    { "SIGTTIN", SIGTTIN },
    { "SIGTTOU", SIGTTOU },
    { "SIGURG", SIGURG },
    { "SIGXCPU", SIGXCPU },
    { "SIGXFSZ", SIGXFSZ },
    { "SIGVTALRM", SIGVTALRM },
    { "SIGPROF", SIGPROF },
    { "SIGWINCH", SIGWINCH },
    { "SIGIO", SIGIO },
#ifdef SIGPWR
    { "SIGPWR", SIGPWR },
#endif
    { "SIGSYS", SIGSYS },
};

typedef void (*sighandler_t)(int);

struct sighandler_defs {
    const char* name;
    sighandler_t handler;
} sighandler_defs[] = {
    { "SIG_IGN", SIG_IGN },
    { "SIG_DFL", SIG_DFL },
};

static int _find_signal(const char* signal_name)
{
    for (int i = 0; i < sizeof(signal_defs) / sizeof(signal_defs[0]); i++) {
        if (strcmp(signal_defs[i].name, signal_name) == 0) {
            return signal_defs[i].signum;
        }
    }
    errno = EINVAL;
    return -1;
}

static sighandler_t _find_sighandler(const char* sighandler_name)
{
    for (int i = 0; i < sizeof(sighandler_defs) / sizeof(sighandler_defs[0]); i++) {
        if (strcmp(sighandler_defs[i].name, sighandler_name) == 0) {
            return sighandler_defs[i].handler;
        }
    }
    errno = EINVAL;
    return (sighandler_t) -1;
}

int minilib_io_signal_set_signal_handler(const char* signal_name, const char* sighandler_name)
{
    errno = 0;

    int signum = _find_signal(signal_name);
    sighandler_t handler = _find_sighandler(sighandler_name);

    if (errno != 0) {
        return -1;
    }

    sighandler_t old_handler = signal(signum, handler);
    if (old_handler == SIG_ERR) {
        return -1;
    }
    return 0;
}

int minilib_io_signal_kill_process(int pid, const char* signal_name)
{
    errno = 0;

    int signum = _find_signal(signal_name);

    if (errno != 0) {
        return -1;
    }

    int err = kill(pid, signum);
    if (err != 0) {
        return -1;
    }
    return 0;
}

