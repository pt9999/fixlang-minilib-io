# Minilib.IO.FileSystem

Defined in minilib-io@0.6.5

File system module. For example, finding files, checks if file or directory exists,
getting file size and last modified time.

## Values

### namespace Minilib.IO.FileSystem

#### creat

Type: `Std::String -> Std::U32 -> Std::IO::IOFail Std::I32`

Creates a new file or rewrites an existing one.

For details, see Linux manual page for [creat(3p)](https://man7.org/linux/man-pages/man3/creat.3p.html).

#### directory_exists

Type: `Std::String -> Std::IO Std::Bool`

Returns true if the specified directory exists.

#### fdopen

Type: `Std::I32 -> Std::String -> Std::IO::IOFail Std::IO::IOHandle`

Associates a stream with a file descriptor.

For details, see Linux manual page for [fdopen(3p)](https://man7.org/linux/man-pages/man3/fdopen.3p.html).

#### file_exists

Type: `Std::String -> Std::IO Std::Bool`

Returns true if the specified file exists.

#### find_files

Type: `Std::String -> Std::IO::IOFail (Std::Array Std::String)`

`find_files(dir_path)` finds all files under
specified directory and its subdirectories.

Example:
```
find_files("./lib")
==> ["./lib/io/errno.fix","./lib/io/file_system.fix","./lib/io/path.fix","./lib/io/platform.fix","./lib/io/signal.fix"]
```

#### list_dir

Type: `Std::String -> Std::IO::IOFail (Std::Array Std::String)`

Lists a directory.
Returns filenames in the specified directory.
The filenames will be sorted in lexicographical order.

#### make_dirs

Type: `Std::String -> Std::Option Std::U32 -> Std::IO::IOFail ()`

`make_dirs(dir_path, mode)` creates specified directory
as well as its parent directories recursively.
If the directory already exists, it does nothing.
If `mode` is `none()`, octal 0777 is used as a mode.
This mode is modified by the process's umask in the usual way.

#### mkdir

Type: `Std::String -> Std::Option Std::U32 -> Std::IO::IOFail ()`

`mkdir(path, mode)` creates a directory.
If `mode` is `none()`, octal 0777 is used as a mode.
This mode is modified by the process's umask in the usual way.

#### open_pipe

Type: `Std::IO::IOFail (Std::IO::IOHandle, Std::IO::IOHandle)`

Creates a pipe stream. It returns `(read_fh, write_fh)` where `read_fd` is the stream of
read-end of the pipe, and `write_fd` is the stream of write-end of the pipe.

For details, see Linux manual page for [pipe(2)](https://man7.org/linux/man-pages/man2/pipe.2.html).

#### pipe

Type: `Std::IO::IOFail (Std::I32, Std::I32)`

Creates a pipe. It returns `(read_fd, write_fd)` where `read_fd` is the file descriptor of
read-end of the pipe, and `write_fd` is the file descriptor of write-end of the pipe.

For details, see Linux manual page for [pipe(2)](https://man7.org/linux/man-pages/man2/pipe.2.html).

#### realpath

Type: `Std::String -> Std::IO::IOFail Std::String`

Returns the canonicalized absolute pathname.

For detials, see Linux manual page for [realpath(3)](https://man7.org/linux/man-pages/man3/realpath.3.html).

#### rmdir

Type: `Std::String -> Std::IO::IOFail ()`

`rmdir(path)` deletes a directory, which must be empty.

#### unlink

Type: `Std::String -> Std::IO::IOFail ()`

Deletes a name from the filesystem and possibly the file it refers to.

For details, see Linux manual page for [unlink(2)](https://man7.org/linux/man-pages/man2/unlink.2.html).

### namespace Minilib.IO.FileSystem::FileStat

#### is_dir

Type: `Minilib.IO.FileSystem::FileStat -> Std::Bool`

Returns true if it is a directory.

#### is_file

Type: `Minilib.IO.FileSystem::FileStat -> Std::Bool`

Returns true if it is a regular file.

#### st_atim

Type: `Minilib.IO.FileSystem::FileStat -> Time::Time`

#### st_atime

Type: `Minilib.IO.FileSystem::FileStat -> Std::U64`

#### st_blksize

Type: `Minilib.IO.FileSystem::FileStat -> Std::I64`

#### st_blocks

Type: `Minilib.IO.FileSystem::FileStat -> Std::U64`

#### st_ctim

Type: `Minilib.IO.FileSystem::FileStat -> Time::Time`

#### st_ctime

Type: `Minilib.IO.FileSystem::FileStat -> Std::U64`

#### st_dev

Type: `Minilib.IO.FileSystem::FileStat -> Std::U64`

#### st_gid

Type: `Minilib.IO.FileSystem::FileStat -> Std::U32`

#### st_ino

Type: `Minilib.IO.FileSystem::FileStat -> Std::U64`

#### st_mode

Type: `Minilib.IO.FileSystem::FileStat -> Std::U32`

#### st_mtim

Type: `Minilib.IO.FileSystem::FileStat -> Time::Time`

#### st_mtime

Type: `Minilib.IO.FileSystem::FileStat -> Std::U64`

#### st_nlink

Type: `Minilib.IO.FileSystem::FileStat -> Std::U64`

#### st_rdev

Type: `Minilib.IO.FileSystem::FileStat -> Std::U64`

#### st_size

Type: `Minilib.IO.FileSystem::FileStat -> Std::I64`

#### st_uid

Type: `Minilib.IO.FileSystem::FileStat -> Std::U32`

#### stat

Type: `Std::String -> Std::IO::IOFail Minilib.IO.FileSystem::FileStat`

`stat(file_path)` retrieves information about the file pointed to by `file_path`.

For detials, see Linux manual page for [stat(2)](https://man7.org/linux/man-pages/man2/stat.2.html)
and [stat(3type)](https://man7.org/linux/man-pages/man3/stat.3type.html).

## Types and aliases

### namespace Minilib.IO.FileSystem

#### DirHandle

Defined as: `type DirHandle = unbox struct { ...fields... }`

[nofixdoc] Type of a directory handle

##### field `dtor`

Type: `Std::FFI::Destructor Std::Ptr`

#### FileStat

Defined as: `type FileStat = unbox struct { ...fields... }`

Type of file status

##### field `data`

Type: `Std::Array Std::U64`

## Traits and aliases

## Trait implementations