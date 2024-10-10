# `module Minilib.IO.Path`

File Path handling, such as joining paths and retrieving directory name.

# Types and aliases

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.IO.Path`

### `basename : Std::String -> Std::String`

`basename(path)` returns the last non-slash component. The trailing slashes are removed.

### `dirname : Std::String -> Std::String`

`dirname(path)` returns the path with its last non-slash component and trailing slashes removed.
if `path` contains no `/`s, returns `"."`.

### `is_path_sep : Std::U8 -> Std::Bool`

Checks if the byte is a path separator. Currently only '/' is supported.

### `join_paths : Std::Array Std::String -> Std::String`

`join_paths(path_segments)` joins segments into a path.

### `relativize : Std::String -> Std::String -> Std::Result Std::String Std::String`

`base.relativize(target)` constructs a relative path from `base` to `target`.
`base` and `target` should have the same type (i.e. relative path or absolute path).
If only one of `base` and `target` is an absolute path, "different type of path" error is returned.
If `base` == `target`, then an empty string is returned.