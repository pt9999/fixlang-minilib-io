## 0.8.1
### Fixed
- Fixed potential dangling pointers. (`unsafe_from_c_str_ptr` -> `unsafe_from_c_str_ptr_io`)

## 0.8.0
### Changed
- fixproj.toml:
  - Bumped `fix_version` to 1.3.0.
  - Depends on minilib-common@0.12.0, minilib-binary@0.6.0.
  - Moved asynctask to test_dependencies.
  - Removed hashmap from dependencies.

## 0.7.1
### Added
- Minilib.IO.FileSystem: Added `lstat`, `is_symbolic_link`, `symlink`, `unlink_if_exists`.
### Changed
- Minilib.IO.FileSystem: Added a note about broken symlinks to the documentation for `file_exists`, `directory_exists`.

## 0.7.0
### Added
- Minilib.IO.FileSystem: Added `open_temp_file`, `with_temp_file`, `set_file_position`, `get_file_position`.
### Changed
- Functions that return IO/IOFail monads now use MonadIO/MonadIOFail.
- Improved error messages when an operation fails.

## 0.6.12
### Changed
- fixproj.toml: change versions of dependencies to "*"

## 0.6.10
### Added
- Minilib.IO.FileSystem: Added `chdir`, `getcwd`.
### Changed
- Minilib.IO.FileSystem: Changed most of `I32` to `CInt`.
- Minilib.IO.FileSystem: Updated documentation comments.
### Fixed
- Minilib.IO.FileSystem: Made most of `IO` and `IOFail` monads to be lazy.

## 0.6.9
### Changed
- Minilib.IO.Errno: `strerror_r` is now deprecated
- PR#3: update lib.c so that it can be compiled on macOS

## 0.6.7
### Changed
- adopt to type change in IOHandle::from_file_ptr
