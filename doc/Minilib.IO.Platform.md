# `module Minilib.IO.Platform`

Get kernel information such as system name, machine archtecture.

# Types and aliases

## `namespace Minilib.IO.Platform`

### `type UName = unbox struct { ...fields... }`

A type of name and information of current kernel.

#### field `sysname : Std::String`

#### field `nodename : Std::String`

#### field `release : Std::String`

#### field `version : Std::String`

#### field `machine : Std::String`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.IO.Platform`

### `byte_order : Minilib.Encoding.Binary::ByteOrder`

The byte order of platform.

### `get_uname : Std::IO::IOFail Minilib.IO.Platform::UName`

Gets the name and information of current kernel.
It calls POSIX C function `uname()`.

### `uname : Minilib.IO.Platform::UName`

NOTE: `uname` is deprecated. Please use `get_uname`.

The name and information of current kernel.
Calls POSIX C function `uname()`, and split the result by null characters.
NOTE: The system information does not change during program execution,
so this variable is constant.