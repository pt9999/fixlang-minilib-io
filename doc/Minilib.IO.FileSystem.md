# `module Minilib.IO.FileSystem`

File system module. For example, finding files, checks if file or directory exists,
getting file size and last modified time.

# Types and aliases

## `namespace Minilib.IO.FileSystem`

### `type DefStructStat = unbox struct { ...fields... }`

[nofixdoc] A type that represents size info of `struct stat`.

#### field `offsetof_st_dev : Std::I64`

#### field `offsetof_st_ino : Std::I64`

#### field `offsetof_st_nlink : Std::I64`

#### field `offsetof_st_mode : Std::I64`

#### field `offsetof_st_uid : Std::I64`

#### field `offsetof_st_gid : Std::I64`

#### field `offsetof_st_rdev : Std::I64`

#### field `offsetof_st_size : Std::I64`

#### field `offsetof_st_blksize : Std::I64`

#### field `offsetof_st_blocks : Std::I64`

#### field `offsetof_st_atime : Std::I64`

#### field `offsetof_st_mtime : Std::I64`

#### field `offsetof_st_ctime : Std::I64`

#### field `sizeof_struct_stat : Std::I64`

### `type DirHandle = unbox struct { ...fields... }`

[nofixdoc] Type of a directory handle

#### field `dtor : Std::FFI::Destructor Std::Ptr`

### `type FileStat = unbox struct { ...fields... }`

Type of file status

#### field `data : Minilib.Encoding.Binary::ByteBuffer`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.IO.FileSystem`

### `_def_struct_stat : Minilib.IO.FileSystem::DefStructStat`

NOTE: the system information does not change during program execution,
so this variable is constant.

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

## `namespace Minilib.IO.FileSystem::DefStructStat`

### `@offsetof_st_atime : Minilib.IO.FileSystem::DefStructStat -> Std::I64`

Retrieves the field `offsetof_st_atime` from a value of `DefStructStat`.

### `@offsetof_st_blksize : Minilib.IO.FileSystem::DefStructStat -> Std::I64`

Retrieves the field `offsetof_st_blksize` from a value of `DefStructStat`.

### `@offsetof_st_blocks : Minilib.IO.FileSystem::DefStructStat -> Std::I64`

Retrieves the field `offsetof_st_blocks` from a value of `DefStructStat`.

### `@offsetof_st_ctime : Minilib.IO.FileSystem::DefStructStat -> Std::I64`

Retrieves the field `offsetof_st_ctime` from a value of `DefStructStat`.

### `@offsetof_st_dev : Minilib.IO.FileSystem::DefStructStat -> Std::I64`

Retrieves the field `offsetof_st_dev` from a value of `DefStructStat`.

### `@offsetof_st_gid : Minilib.IO.FileSystem::DefStructStat -> Std::I64`

Retrieves the field `offsetof_st_gid` from a value of `DefStructStat`.

### `@offsetof_st_ino : Minilib.IO.FileSystem::DefStructStat -> Std::I64`

Retrieves the field `offsetof_st_ino` from a value of `DefStructStat`.

### `@offsetof_st_mode : Minilib.IO.FileSystem::DefStructStat -> Std::I64`

Retrieves the field `offsetof_st_mode` from a value of `DefStructStat`.

### `@offsetof_st_mtime : Minilib.IO.FileSystem::DefStructStat -> Std::I64`

Retrieves the field `offsetof_st_mtime` from a value of `DefStructStat`.

### `@offsetof_st_nlink : Minilib.IO.FileSystem::DefStructStat -> Std::I64`

Retrieves the field `offsetof_st_nlink` from a value of `DefStructStat`.

### `@offsetof_st_rdev : Minilib.IO.FileSystem::DefStructStat -> Std::I64`

Retrieves the field `offsetof_st_rdev` from a value of `DefStructStat`.

### `@offsetof_st_size : Minilib.IO.FileSystem::DefStructStat -> Std::I64`

Retrieves the field `offsetof_st_size` from a value of `DefStructStat`.

### `@offsetof_st_uid : Minilib.IO.FileSystem::DefStructStat -> Std::I64`

Retrieves the field `offsetof_st_uid` from a value of `DefStructStat`.

### `@sizeof_struct_stat : Minilib.IO.FileSystem::DefStructStat -> Std::I64`

Retrieves the field `sizeof_struct_stat` from a value of `DefStructStat`.

### `act_offsetof_st_atime : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> f Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a functorial action to field `offsetof_st_atime`.

### `act_offsetof_st_blksize : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> f Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a functorial action to field `offsetof_st_blksize`.

### `act_offsetof_st_blocks : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> f Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a functorial action to field `offsetof_st_blocks`.

### `act_offsetof_st_ctime : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> f Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a functorial action to field `offsetof_st_ctime`.

### `act_offsetof_st_dev : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> f Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a functorial action to field `offsetof_st_dev`.

### `act_offsetof_st_gid : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> f Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a functorial action to field `offsetof_st_gid`.

### `act_offsetof_st_ino : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> f Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a functorial action to field `offsetof_st_ino`.

### `act_offsetof_st_mode : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> f Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a functorial action to field `offsetof_st_mode`.

### `act_offsetof_st_mtime : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> f Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a functorial action to field `offsetof_st_mtime`.

### `act_offsetof_st_nlink : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> f Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a functorial action to field `offsetof_st_nlink`.

### `act_offsetof_st_rdev : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> f Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a functorial action to field `offsetof_st_rdev`.

### `act_offsetof_st_size : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> f Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a functorial action to field `offsetof_st_size`.

### `act_offsetof_st_uid : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> f Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a functorial action to field `offsetof_st_uid`.

### `act_sizeof_struct_stat : [f : Std::Functor] (Std::I64 -> f Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> f Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a functorial action to field `sizeof_struct_stat`.

### `mod_offsetof_st_atime : (Std::I64 -> Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a function to field `offsetof_st_atime`.

### `mod_offsetof_st_blksize : (Std::I64 -> Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a function to field `offsetof_st_blksize`.

### `mod_offsetof_st_blocks : (Std::I64 -> Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a function to field `offsetof_st_blocks`.

### `mod_offsetof_st_ctime : (Std::I64 -> Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a function to field `offsetof_st_ctime`.

### `mod_offsetof_st_dev : (Std::I64 -> Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a function to field `offsetof_st_dev`.

### `mod_offsetof_st_gid : (Std::I64 -> Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a function to field `offsetof_st_gid`.

### `mod_offsetof_st_ino : (Std::I64 -> Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a function to field `offsetof_st_ino`.

### `mod_offsetof_st_mode : (Std::I64 -> Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a function to field `offsetof_st_mode`.

### `mod_offsetof_st_mtime : (Std::I64 -> Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a function to field `offsetof_st_mtime`.

### `mod_offsetof_st_nlink : (Std::I64 -> Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a function to field `offsetof_st_nlink`.

### `mod_offsetof_st_rdev : (Std::I64 -> Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a function to field `offsetof_st_rdev`.

### `mod_offsetof_st_size : (Std::I64 -> Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a function to field `offsetof_st_size`.

### `mod_offsetof_st_uid : (Std::I64 -> Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a function to field `offsetof_st_uid`.

### `mod_sizeof_struct_stat : (Std::I64 -> Std::I64) -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by applying a function to field `sizeof_struct_stat`.

### `set_offsetof_st_atime : Std::I64 -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by setting field `offsetof_st_atime` to a specified one.

### `set_offsetof_st_blksize : Std::I64 -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by setting field `offsetof_st_blksize` to a specified one.

### `set_offsetof_st_blocks : Std::I64 -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by setting field `offsetof_st_blocks` to a specified one.

### `set_offsetof_st_ctime : Std::I64 -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by setting field `offsetof_st_ctime` to a specified one.

### `set_offsetof_st_dev : Std::I64 -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by setting field `offsetof_st_dev` to a specified one.

### `set_offsetof_st_gid : Std::I64 -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by setting field `offsetof_st_gid` to a specified one.

### `set_offsetof_st_ino : Std::I64 -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by setting field `offsetof_st_ino` to a specified one.

### `set_offsetof_st_mode : Std::I64 -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by setting field `offsetof_st_mode` to a specified one.

### `set_offsetof_st_mtime : Std::I64 -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by setting field `offsetof_st_mtime` to a specified one.

### `set_offsetof_st_nlink : Std::I64 -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by setting field `offsetof_st_nlink` to a specified one.

### `set_offsetof_st_rdev : Std::I64 -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by setting field `offsetof_st_rdev` to a specified one.

### `set_offsetof_st_size : Std::I64 -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by setting field `offsetof_st_size` to a specified one.

### `set_offsetof_st_uid : Std::I64 -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by setting field `offsetof_st_uid` to a specified one.

### `set_sizeof_struct_stat : Std::I64 -> Minilib.IO.FileSystem::DefStructStat -> Minilib.IO.FileSystem::DefStructStat`

Updates a value of `DefStructStat` by setting field `sizeof_struct_stat` to a specified one.

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

### `@data : Minilib.IO.FileSystem::FileStat -> Minilib.Encoding.Binary::ByteBuffer`

Retrieves the field `data` from a value of `FileStat`.

### `act_data : [f : Std::Functor] (Minilib.Encoding.Binary::ByteBuffer -> f Minilib.Encoding.Binary::ByteBuffer) -> Minilib.IO.FileSystem::FileStat -> f Minilib.IO.FileSystem::FileStat`

Updates a value of `FileStat` by applying a functorial action to field `data`.

### `is_dir : Minilib.IO.FileSystem::FileStat -> Std::Bool`

Returns true if it is a directory.

### `is_file : Minilib.IO.FileSystem::FileStat -> Std::Bool`

Returns true if it is a regular file.

### `mod_data : (Minilib.Encoding.Binary::ByteBuffer -> Minilib.Encoding.Binary::ByteBuffer) -> Minilib.IO.FileSystem::FileStat -> Minilib.IO.FileSystem::FileStat`

Updates a value of `FileStat` by applying a function to field `data`.

### `set_data : Minilib.Encoding.Binary::ByteBuffer -> Minilib.IO.FileSystem::FileStat -> Minilib.IO.FileSystem::FileStat`

Updates a value of `FileStat` by setting field `data` to a specified one.

### `st_atime : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_blksize : Minilib.IO.FileSystem::FileStat -> Std::I64`

### `st_blocks : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_ctime : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_dev : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_gid : Minilib.IO.FileSystem::FileStat -> Std::U32`

### `st_ino : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_mode : Minilib.IO.FileSystem::FileStat -> Std::U32`

### `st_mtime : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_nlink : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_rdev : Minilib.IO.FileSystem::FileStat -> Std::U64`

### `st_size : Minilib.IO.FileSystem::FileStat -> Std::I64`

### `st_uid : Minilib.IO.FileSystem::FileStat -> Std::U32`

### `stat : Std::String -> Std::IO::IOFail Minilib.IO.FileSystem::FileStat`

`stat(file_path)` retrieves information about the file pointed to by `file_path`.