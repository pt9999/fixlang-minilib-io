# `module Minilib.IO.Errno`

Functions for `errno` which is set by system calls and some library functions.

# Types and aliases

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.IO.Errno`

### `clear_errno : Std::IO ()`

Clears `errno`, the global variable that stores the last error number.

### `get_errno : Std::IO Std::I32`

Gets the last error number from `errno`.

### `get_last_error : Std::IO Std::String`

Gets the error message corresponding to the last error number.

### `strerror : Std::I32 -> Std::IO Std::String`

Converts the error number returned by `get_errno` to a string.
This function may have race conditions, but is more portable.

### `strerror_r : Std::I32 -> Std::IO Std::String`

Converts the error number returned by `get_errno` to a string.
This function has no race conditions, but is less portable.  (This function is GNU C library specific)