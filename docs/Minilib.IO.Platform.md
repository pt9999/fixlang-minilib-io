# Minilib.IO.Platform

Defined in minilib-io@0.9.0

Get kernel information such as system name, machine archtecture.

## Values

### namespace Minilib.IO.Platform

#### byte_order

Type: `Minilib.Encoding.Binary::ByteOrder`

The byte order of platform.

#### get_uname

Type: `[m : Minilib.Monad.IO::MonadIOFail] m Minilib.IO.Platform::UName`

Gets the name and information of current kernel.
It calls POSIX C function `uname()`.

#### uname

**Deprecated**: Use `get_uname` instead.

Type: `Minilib.IO.Platform::UName`

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