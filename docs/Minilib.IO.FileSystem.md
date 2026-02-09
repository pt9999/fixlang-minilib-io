# Minilib.IO.FileSystem

Defined in minilib-io@0.8.0

File system module. For example, finding files, checks if file or directory exists,
getting file size and last modified time.

## Values

### namespace Minilib.IO.FileSystem

#### chdir

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::Path -> m ()`

`chdir(path)` changes the current working directory of the calling process to the specified directory.

##### Parameters

- `dir_path`: a directory path

#### creat

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::String -> Std::U32 -> m Std::FFI::CInt`

Creates a new file or rewrites an existing one.

For details, see Linux manual page for [creat(3p)](https://man7.org/linux/man-pages/man3/creat.3p.html).

##### Parameters

- `path`: a file path to be created
- `mode`: a file mode of the created file

#### directory_exists

Type: `[m : Minilib.Monad.IO::MonadIO] Std::String -> m Std::Bool`

Returns true if the specified directory exists.

NOTE: If `file_path` is a broken symbolic link, it returns false.

##### Parameters

- `dir_path`: a directory path

#### fdopen

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::FFI::CInt -> Std::String -> m Std::IO::IOHandle`

Associates a stream with a file descriptor.

For details, see Linux manual page for [fdopen(3p)](https://man7.org/linux/man-pages/man3/fdopen.3p.html).

##### Parameters

- `fd`: a file descriptor
- `mode` a file open mode, such as "r", "w", "a" etc.

#### file_exists

Type: `[m : Minilib.Monad.IO::MonadIO] Std::String -> m Std::Bool`

Returns true if the specified file exists.

NOTE: If `file_path` is a broken symbolic link, it returns false.

##### Parameters

- `file_path`: a file path

#### find_files

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::String -> m (Std::Array Std::String)`

`find_files(dir_path)` finds all files under
specified directory and its subdirectories.

Example:
```
find_files("./lib")
==> ["./lib/io/errno.fix","./lib/io/file_system.fix","./lib/io/path.fix","./lib/io/platform.fix","./lib/io/signal.fix"]
```

##### Parameters

- `dir_path`: a directory path

#### get_file_position

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::IO::IOHandle -> m Std::FFI::CLong`

Gets the file position of a file handle relative to the start of the file.

##### Parameters

- `handle`: A file handle

#### getcwd

Type: `[m : Minilib.Monad.IO::MonadIOFail] m Std::String`

`getcwd` returns an absolute pathname of the current working directory.

#### list_dir

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::String -> m (Std::Array Std::String)`

Lists a directory.
Returns filenames in the specified directory.
The filenames will be sorted in lexicographical order.

##### Parameters

- `dir_path`: a directory path

#### make_dirs

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::String -> Std::Option Std::U32 -> m ()`

`make_dirs(dir_path, mode)` creates specified directory
as well as its parent directories recursively.
If the directory already exists, it does nothing.
If `mode` is `none()`, octal 0777 is used as a mode.
This mode is modified by the process's umask in the usual way.

##### Parameters

- `dir_path`: the directory path to be created
- `mode`: `some()` of a file mode of the created directories, or `none()`

#### mkdir

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::String -> Std::Option Std::U32 -> m ()`

`mkdir(dir_path, mode)` creates a directory.
If `mode` is `none()`, octal 0777 is used as a mode.
This mode is modified by the process's umask in the usual way.

##### Parameters

- `dir_path`: the directory path to be created
- `mode`: `some()` of a file mode of the created directory, or `none()`

#### open_pipe

Type: `[m : Minilib.Monad.IO::MonadIOFail] m (Std::IO::IOHandle, Std::IO::IOHandle)`

Creates a pipe stream. It returns `(read_fh, write_fh)` where `read_fd` is the stream of
read-end of the pipe, and `write_fd` is the stream of write-end of the pipe.

For details, see Linux manual page for [pipe(2)](https://man7.org/linux/man-pages/man2/pipe.2.html).

#### open_temp_file

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::String -> Std::Bool -> m (Std::String, Std::IO::IOHandle)`

Creates and opens a unique temporary file.

Returns the file path and file handle of the created temporary file.

The temporary file is opened in read/write mode.

If `auto_unlink` is true, the temporary file is unlinked from the filesystem as soon as it is created and opened.
If `auto_unlink` is false, the temporary file remains on the filesystem.

The caller is responsible for performing any cleanup such as closing the file handle and deleting the temporary file.

##### Parameters

- `filepath_prefix`: The file path prefix for the temporary file being created.
- `auto_unlink`: If true, the temporary file will be unlinked from the file system as soon as it is created and opened.

#### pipe

Type: `[m : Minilib.Monad.IO::MonadIOFail] m (Std::FFI::CInt, Std::FFI::CInt)`

Creates a pipe. It returns `(read_fd, write_fd)` where `read_fd` is the file descriptor of
read-end of the pipe, and `write_fd` is the file descriptor of write-end of the pipe.

For details, see Linux manual page for [pipe(2)](https://man7.org/linux/man-pages/man2/pipe.2.html).

#### realpath

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::String -> m Std::String`

Returns the canonicalized absolute pathname.

For detials, see Linux manual page for [realpath(3)](https://man7.org/linux/man-pages/man3/realpath.3.html).

##### Parameters

- `path`: a file or directory path, which may be a relative path

#### rmdir

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::String -> m ()`

`rmdir(path)` deletes a directory, which must be empty.

##### Parameters

- `dir_path`: the directory path to be deleted

#### set_file_position

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::IO::IOHandle -> Std::FFI::CLong -> Minilib.IO.FileSystem::SeekWhence -> m ()`

Sets the file position of a file handle.

##### Parameters

- `handle`: A file handle
- `offset`: An offset relative to the reference position specified by `whence`
- `whence`: The reference position

#### symlink

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::String -> Std::String -> m ()`

Creates a symbolic link.

For details, see Linux manual page for [symlink(2)](https://man7.org/linux/man-pages/man2/symlink.2.html).

##### Parameters

- `target`: a file path the symolic link refers to
- `link_path`: a path of the symbolic link

#### unlink

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::String -> m ()`

Deletes a name from the filesystem and possibly the file it refers to.

For details, see Linux manual page for [unlink(2)](https://man7.org/linux/man-pages/man2/unlink.2.html).

##### Parameters

- `path`: a file path to be deleted

#### unlink_if_exists

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::String -> m ()`

Deletes a name from the filesystem only if the name exists, and possibly the file it refers to.

If the name points to a symbolic link, it deletes that symbolic link.

For details, see Linux manual page for [unlink(2)](https://man7.org/linux/man-pages/man2/unlink.2.html).

##### Parameters

- `path`: a path to be deleted

#### with_temp_file

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::String -> Std::Bool -> ((Std::String, Std::IO::IOHandle) -> Std::IO::IOFail a) -> m a`

Creates and opens a unique temporary file, performs `body`, then finally
performs a cleanup.

The `body` is a function that takes a file path and a file handle as arguments and returns an IOFail monad.

The temporary file is opened in read/write mode.

If `auto_unlink` is true, the temporary file is unlinked from the filesystem as soon as it is created and opened.
If `auto_unlink` is false, the temporary file remains on the filesystem until the cleanup will be performed.

On cleanup, the file handle will be closed, and the temporary file is unlinked if exists.

##### Parameters

- `filepath_prefix`: The file path prefix for the temporary file being created.
- `auto_unlink`: If true, the temporary file will be unlinked from the file system as soon as it is created and opened.
- `body`: A function that takes a file path and a file handle as arguments and returns an IOFail monad.

### namespace Minilib.IO.FileSystem::FileStat

#### is_dir

Type: `Minilib.IO.FileSystem::FileStat -> Std::Bool`

Returns true if it is a directory.

##### Parameters

- `file_stat`: a file status obtained by `stat`

#### is_file

Type: `Minilib.IO.FileSystem::FileStat -> Std::Bool`

Returns true if it is a regular file.

##### Parameters

- `file_stat`: a file status obtained by `stat`

#### is_symbolic_link

Type: `Minilib.IO.FileSystem::FileStat -> Std::Bool`

Returns true if it is a symbolic link.

##### Parameters

- `file_stat`: a file status obtained by `lstat`

#### lstat

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::String -> m Minilib.IO.FileSystem::FileStat`

`lstat(file_path)` retrieves information about the file pointed to by `file_path`.
If `file_path` is a symbolic link, it retrieves information about the symbolic link itself,
not the file it references.

For detials, see Linux manual page for [lstat(2)](https://man7.org/linux/man-pages/man2/lstat.2.html)
and [stat(3type)](https://man7.org/linux/man-pages/man3/stat.3type.html).

##### Parameters

- `file_path`: a file path

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

Type: `[m : Minilib.Monad.IO::MonadIOFail] Std::String -> m Minilib.IO.FileSystem::FileStat`

`stat(file_path)` retrieves information about the file pointed to by `file_path`.

For detials, see Linux manual page for [stat(2)](https://man7.org/linux/man-pages/man2/stat.2.html)
and [stat(3type)](https://man7.org/linux/man-pages/man3/stat.3type.html).

##### Parameters

- `file_path`: a file path

## Types and aliases

### namespace Minilib.IO.FileSystem

#### DirHandle

Defined as: `type DirHandle = unbox struct { ...fields... }`

Type of a directory handle (used internally)

##### field `dtor`

Type: `Std::FFI::Destructor Std::Ptr`

#### FileStat

Defined as: `type FileStat = unbox struct { ...fields... }`

Type of file status

##### field `data`

Type: `Std::Array Std::U64`

#### SeekWhence

Defined as: `type SeekWhence = unbox union { ...variants... }`

The type of file seek reference position

##### variant `seek_set`

Type: `()`

The start of the file

##### variant `seek_cur`

Type: `()`

The current position

##### variant `seek_end`

Type: `()`

The end of the file

## Traits and aliases

## Trait implementations