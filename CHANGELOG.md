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
