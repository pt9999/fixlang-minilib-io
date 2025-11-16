# Minilib.IO.Path

Defined in minilib-io@0.6.2

File Path handling, such as joining paths and retrieving directory name.

## Values

### namespace Minilib.IO.Path

#### basename

Type: `Std::String -> Std::String`

`basename(path)` returns the last non-slash component. The trailing slashes are removed.
Example:
```
basename("foo/bar/")
==> "bar"
basename("foo/bar/baz")
==> "baz"
basename("foo")
==> "foo"
basename("/you/can/specify/absolute/path")
==> "path"
```

#### dirname

Type: `Std::String -> Std::String`

`dirname(path)` returns the path with its last non-slash component and trailing slashes removed.
if `path` contains no `/`s, returns `"."`.
Example:
```
dirname("foo/bar/")
==> "foo"
dirname("foo/bar/baz")
==> "foo/bar"
dirname("foo")
==> "."
dirname("/you/can/specify/absolute/path")
==> "/you/can/specify/absolute"
```

#### is_path_sep

Type: `Std::U8 -> Std::Bool`

Checks if the byte is a path separator. Currently only '/' is supported.

#### join_paths

Type: `Std::Array Std::String -> Std::String`

`join_paths(path_segments)` joins segments into a path.
Example:
```
join_paths(["foo", "bar", "baz"])
==> "foo/bar/baz"
join_paths(["/usr/", "local", "bin/fix"])
==> "/usr/local/bin/fix"
```

#### relativize

Type: `Std::String -> Std::String -> Std::Result Std::ErrMsg Std::String`

`base.relativize(target)` constructs a relative path from `base` to `target`.
`base` and `target` should have the same type (i.e. relative path or absolute path).
If only one of `base` and `target` is an absolute path, "different type of path" error is returned.
If `base` == `target`, then an empty string is returned.
```
"/usr/".relativize("/usr/bin/ls")
==> "bin/ls"
"/usr/local".relativize("/usr/bin/ls")
==> "../bin/ls"
"foo/bar/baz".relativize("abc/def")
==> "../../../abc/def"
```

## Types and aliases

## Traits and aliases

## Trait implementations