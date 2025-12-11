# Minilib.IO.Platform

Defined in minilib-io@0.6.5

Get kernel information such as system name, machine archtecture.

## Values

### namespace Minilib.IO.Platform

#### byte_order

Type: `Minilib.Encoding.Binary::ByteOrder`

The byte order of platform.

#### get_uname

Type: `Std::IO::IOFail Minilib.IO.Platform::UName`

Gets the name and information of current kernel.
It calls POSIX C function `uname()`.

#### uname

Type: `Minilib.IO.Platform::UName`

NOTE: `uname` is deprecated. Please use `get_uname`.

The name and information of current kernel.
Calls POSIX C function `uname()`, and split the result by null characters.
NOTE: The system information does not change during program execution,
so this variable is constant.

## Types and aliases

### namespace Minilib.IO.Platform

#### UName

Defined as: `type UName = unbox struct { ...fields... }`

A type of name and information of current kernel.

##### field `sysname`

Type: `Std::String`

##### field `nodename`

Type: `Std::String`

##### field `release`

Type: `Std::String`

##### field `version`

Type: `Std::String`

##### field `machine`

Type: `Std::String`

## Traits and aliases

## Trait implementations