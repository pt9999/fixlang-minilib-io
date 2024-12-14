#include <sys/types.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int minilib_iofs_stat(const char* pathname, uint64_t *ret)
{
    struct stat st;
    int err = stat(pathname, &st);
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
    ret[10] = (uint64_t)st.st_atim.tv_sec;
    ret[11] = (uint64_t)st.st_atim.tv_nsec;
    ret[12] = (uint64_t)st.st_mtim.tv_sec;
    ret[13] = (uint64_t)st.st_mtim.tv_nsec;
    ret[14] = (uint64_t)st.st_ctim.tv_sec;
    ret[15] = (uint64_t)st.st_ctim.tv_nsec;
    return 0;
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

