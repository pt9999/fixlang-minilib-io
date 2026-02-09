# Minilib.IO.Errno

Defined in minilib-io@0.8.0

Functions for `errno` which is set by system calls and some library functions.

## Values

### namespace Minilib.IO.Errno

#### get_last_error

Type: `[m : Minilib.Monad.IO::MonadIO] m Std::String`

Gets the error message corresponding to the last error number.

#### strerror

Type: `[m : Minilib.Monad.IO::MonadIO] Std::I32 -> m Std::String`

Converts the error number returned by `get_errno` to a string.
This function may have race conditions, but is more portable.

#### strerror_r

Type: `[m : Minilib.Monad.IO::MonadIO] Std::I32 -> m Std::String`

Deprecated: Now this function is identical to `strerror`.

## Types and aliases

## Traits and aliases

## Trait implementations