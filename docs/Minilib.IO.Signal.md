# `module Minilib.IO.Signal`

Unix signal handling

# Types and aliases

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.IO.Signal`

### `kill_process : Std::I64 -> Std::String -> Std::IO::IOFail ()`

### `set_signal_handler : Std::String -> Std::String -> Std::IO::IOFail ()`

`set_signal_handler(signal_name, sighandle_name)` sets the handler for the signal.
`signal_name` should be one of `signal_names`.
`sighandle_name` should be one of `sighandler_names`.

### `sighandler_names : Std::Array Std::String`

An array of supported signal handler names.

### `signal_names : Std::Array Std::String`

An array of supported signal names.