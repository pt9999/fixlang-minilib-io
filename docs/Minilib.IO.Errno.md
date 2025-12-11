# Minilib.IO.Errno

Defined in minilib-io@0.6.4

Functions for `errno` which is set by system calls and some library functions.

## Values

### namespace Minilib.IO.Errno

#### get_last_error

Type: `Std::IO Std::String`

Gets the error message corresponding to the last error number.

#### strerror

Type: `Std::I32 -> Std::IO Std::String`

Converts the error number returned by `get_errno` to a string.
This function may have race conditions, but is more portable.

#### strerror_r

Type: `Std::I32 -> Std::IO Std::String`

Converts the error number returned by `get_errno` to a string.
This function has no race conditions, but is less portable.  (This function is GNU C library specific)

## Types and aliases

## Traits and aliases

## Trait implementations