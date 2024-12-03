# `module Minilib.IO.FileSystem`

File system module. For example, finding files, checks if file or directory exists,
getting file size and last modified time.

# Types and aliases

## `namespace Minilib.IO.FileSystem`

### `type DirHandle = unbox struct { ...fields... }`

[nofixdoc] Type of a directory handle

#### field `dtor : Std::FFI::Destructor Std::Ptr`

### `type FileStat = unbox struct { ...fields... }`

Type of file status

#### field `data : Std::Array Std::U64`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.IO.FileSystem`

### `_opendir : Std::String -> Std::IO::IOFail Minilib.IO.FileSystem::DirHandle`

### `_readdir : Minilib.IO.FileSystem::DirHandle -> Std::IO::IOFail Std::String`

### `creat : Std::String -> Std::U32 -> Std::IO::IOFail Std::I32`

Creates a new file or rewrites an existing one.
For details, see Linux manual page for [creat()](https://man7.org/linux/man-pages/man3/creat.3p.html).

### `directory_exists : Std::String -> Std::IO Std::Bool`

Returns true if the specified directory exists.

### `fdopen : Std::I32 -> Std::String -> Std::IO::IOFail Std::IO::IOHandle`

Associates a stream with a file descriptor.
For details, see Linux manual page for [fdopen()](https://man7.org/linux/man-pages/man3/fdopen.3p.html).

### `fflush : Std::IO::IOHandle -> Std::IO::IOFail ()`

Flushes a file stream.
For details, see Linux manual page for [fflush()](https://man7.org/linux/man-pages/man3/fflush.3.html).

### `file_exists : Std::String -> Std::IO Std::Bool`

Returns true if the specified file exists.

### `find_files : Std::String -> Std::IO::IOFail (Std::Array Std::String)`

`find_files(dir_path)` finds all files under
specified directory and its subdirectories.

### `list_dir : Std::String -> Std::IO::IOFail (Std::Array Std::String)`

Lists a directory.
Returns filenames in the specified directory.
The filenames will be sorted in lexicographical order.

### `make_dirs : Std::String -> Std::Option Std::U32 -> Std::IO::IOFail ()`

`make_dirs(dir_path, mode)` creates specified directory
as well as its parent directories recursively.
If the directory already exists, it does nothing.
If `mode` is `none()`, octal 0777 is used as a mode.
This mode is modified by the process's umask in the usual way.

### `mkdir : Std::String -> Std::Option Std::U32 -> Std::IO::IOFail ()`

`mkdir(path, mode)` creates a directory.
If `mode` is `none()`, octal 0777 is used as a mode.
This mode is modified by the process's umask in the usual way.

### `open_pipe : Std::IO::IOFail (Std::IO::IOHandle, Std::IO::IOHandle)`

Creates a pipe stream. It returns `(read_fh, write_fh)` where `read_fd` is the stream of
read-end of the pipe, and `write_fd` is the stream of write-end of the pipe.
For details, see Linux manual page for [pipe()](https://man7.org/linux/man-pages/man2/pipe.2.html).

### `pipe : Std::IO::IOFail (Std::I32, Std::I32)`

Creates a pipe. It returns `(read_fd, write_fd)` where `read_fd` is the file descriptor of
read-end of the pipe, and `write_fd` is the file descriptor of write-end of the pipe.
For details, see Linux manual page for [pipe()](https://man7.org/linux/man-pages/man2/pipe.2.html).

### `realpath : Std::String -> Std::IO::IOFail Std::String`

Returns the canonicalized absolute pathname.
For detials, see Linux manual page for [realpath()](https://man7.org/linux/man-pages/man3/realpath.3.html).

### `rmdir : Std::String -> Std::IO::IOFail ()`

`rmdir(path)` deletes a directory, which must be empty.

### `set_unbuffered_mode : Std::IO::IOHandle -> Std::IO ()`

Sets IOHandle to unbuffered mode.
For detials, see Linux manual page for [setbuf()](https://man7.org/linux/man-pages/man3/setbuf.3.html).
NOTE: When a fix program is invoked by `run_with_stream()`,
      then the stdout and stderr becomes not a TTY but a file stream.
      So the stdout becomes block-buffered. The stderr also seems to be block-buffered.

### `unlink : Std::String -> Std::IO::IOFail ()`

Deletes a name from the filesystem and possibly the file it refers to.
For details, see Linux manual page for [unlink()](https://man7.org/linux/man-pages/man2/unlink.2.html).

## `namespace Minilib.IO.FileSystem::DirHandle`

### `@dtor : Minilib.IO.FileSystem::DirHandle -> Std::FFI::Destructor Std::Ptr`

Retrieves the field `dtor` from a value of `DirHandle`.

### `act_dtor : [f : Std::Functor] (Std::FFI::Destructor Std::Ptr -> f (Std::FFI::Destructor Std::Ptr)) -> Minilib.IO.FileSystem::DirHandle -> f Minilib.IO.FileSystem::DirHandle`

Updates a value of `DirHandle` by applying a functorial action to field `dtor`.

### `mod_dtor : (Std::FFI::Destructor Std::Ptr -> Std::FFI::Destructor Std::Ptr) -> Minilib.IO.FileSystem::DirHandle -> Minilib.IO.FileSystem::DirHandle`

Updates a value of `DirHandle` by applying a function to field `dtor`.

### `set_dtor : Std::FFI::Destructor Std::Ptr -> Minilib.IO.FileSystem::DirHandle -> Minilib.IO.FileSystem::DirHandle`

Updates a value of `DirHandle` by setting field `dtor` to a specified one.

## `namespace Minilib.IO.FileSystem::FileStat`

### `@data : Minilib.IO.FileSystem::FileStat -> Std::Array Std::U64`

Retrieves the field `data` from a value of `FileStat`.

### `act_data : [f : Std::Functor] (Std::Array Std::U64 -> f (Std::Array Std::U64)) -> Minilib.IO.FileSystem::FileStat -> f Minilib.IO.FileSystem::FileStat`

Updates a value of `FileStat` by applying a functorial action to field `data`.

### `is_dir : Minilib.IO.FileSystem::FileStat -> Std::Bool`

Returns true if it is a directory.

### `is_file : Minilib.IO.FileSystem::FileStat -> Std::Bool`

Returns true if it is a regular file.

### `mod_data : (Std::Array Std::U64 -> Std::Array Std::U64) -> Minilib.IO.FileSystem::FileStat -> Minilib.IO.FileSystem::FileStat`

Updates a value of `FileStat` by applying a function to field `data`.

### `set_data : Std::Array Std::U64 -> Minilib.IO.FileSystem::FileStat -> Minilib.IO.FileSystem::FileStat`

Updates a value of `FileStat` by setting field `data` to a specified one.

### `st_atim : Minilib.IO.FileSystem::FileStat -> Time::Time`

### `st_atime : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_blksize : Minilib.IO.FileSystem::FileStat -> Std::I64`

### `st_blocks : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_ctim : Minilib.IO.FileSystem::FileStat -> Time::Time`

### `st_ctime : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_dev : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_gid : Minilib.IO.FileSystem::FileStat -> Std::U32`

### `st_ino : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_mode : Minilib.IO.FileSystem::FileStat -> Std::U32`

### `st_mtim : Minilib.IO.FileSystem::FileStat -> Time::Time`

### `st_mtime : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_nlink : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_rdev : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_size : Minilib.IO.FileSystem::FileStat -> Std::I64`

### `st_uid : Minilib.IO.FileSystem::FileStat -> Std::U32`

### `stat : Std::String -> Std::IO::IOFail Minilib.IO.FileSystem::FileStat`

`stat(file_path)` retrieves information about the file pointed to by `file_path`.