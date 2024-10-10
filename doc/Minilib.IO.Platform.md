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

### `uname : Minilib.IO.Platform::UName`

The name and information of current kernel.
Calls POSIX C function `uname()`, and split the result by null characters.
NOTE: The system information does not change during program execution,
so this variable is constant.

## `namespace Minilib.IO.Platform::UName`

### `@machine : Minilib.IO.Platform::UName -> Std::String`

Retrieves the field `machine` from a value of `UName`.

### `@nodename : Minilib.IO.Platform::UName -> Std::String`

Retrieves the field `nodename` from a value of `UName`.

### `@release : Minilib.IO.Platform::UName -> Std::String`

Retrieves the field `release` from a value of `UName`.

### `@sysname : Minilib.IO.Platform::UName -> Std::String`

Retrieves the field `sysname` from a value of `UName`.

### `@version : Minilib.IO.Platform::UName -> Std::String`

Retrieves the field `version` from a value of `UName`.

### `act_machine : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.IO.Platform::UName -> f Minilib.IO.Platform::UName`

Updates a value of `UName` by applying a functorial action to field `machine`.

### `act_nodename : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.IO.Platform::UName -> f Minilib.IO.Platform::UName`

Updates a value of `UName` by applying a functorial action to field `nodename`.

### `act_release : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.IO.Platform::UName -> f Minilib.IO.Platform::UName`

Updates a value of `UName` by applying a functorial action to field `release`.

### `act_sysname : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.IO.Platform::UName -> f Minilib.IO.Platform::UName`

Updates a value of `UName` by applying a functorial action to field `sysname`.

### `act_version : [f : Std::Functor] (Std::String -> f Std::String) -> Minilib.IO.Platform::UName -> f Minilib.IO.Platform::UName`

Updates a value of `UName` by applying a functorial action to field `version`.

### `mod_machine : (Std::String -> Std::String) -> Minilib.IO.Platform::UName -> Minilib.IO.Platform::UName`

Updates a value of `UName` by applying a function to field `machine`.

### `mod_nodename : (Std::String -> Std::String) -> Minilib.IO.Platform::UName -> Minilib.IO.Platform::UName`

Updates a value of `UName` by applying a function to field `nodename`.

### `mod_release : (Std::String -> Std::String) -> Minilib.IO.Platform::UName -> Minilib.IO.Platform::UName`

Updates a value of `UName` by applying a function to field `release`.

### `mod_sysname : (Std::String -> Std::String) -> Minilib.IO.Platform::UName -> Minilib.IO.Platform::UName`

Updates a value of `UName` by applying a function to field `sysname`.

### `mod_version : (Std::String -> Std::String) -> Minilib.IO.Platform::UName -> Minilib.IO.Platform::UName`

Updates a value of `UName` by applying a function to field `version`.

### `set_machine : Std::String -> Minilib.IO.Platform::UName -> Minilib.IO.Platform::UName`

Updates a value of `UName` by setting field `machine` to a specified one.

### `set_nodename : Std::String -> Minilib.IO.Platform::UName -> Minilib.IO.Platform::UName`

Updates a value of `UName` by setting field `nodename` to a specified one.

### `set_release : Std::String -> Minilib.IO.Platform::UName -> Minilib.IO.Platform::UName`

Updates a value of `UName` by setting field `release` to a specified one.

### `set_sysname : Std::String -> Minilib.IO.Platform::UName -> Minilib.IO.Platform::UName`

Updates a value of `UName` by setting field `sysname` to a specified one.

### `set_version : Std::String -> Minilib.IO.Platform::UName -> Minilib.IO.Platform::UName`

Updates a value of `UName` by setting field `version` to a specified one.