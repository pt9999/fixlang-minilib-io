# Minilib.IO.Signal

Defined in minilib-io@0.6.0

Unix signal handling

## Values

### namespace Minilib.IO.Signal

#### kill_process

Type: `Std::I64 -> Std::String -> Std::IO::IOFail ()`

#### set_signal_handler

Type: `Std::String -> Std::String -> Std::IO::IOFail ()`

`set_signal_handler(signal_name, sighandle_name)` sets the handler for the signal.
`signal_name` should be one of `signal_names`.
`sighandle_name` should be one of `sighandler_names`.

#### sighandler_names

Type: `Std::Array Std::String`

An array of supported signal handler names.

#### signal_names

Type: `Std::Array Std::String`

An array of supported signal names.

## Types and aliases

## Traits and aliases

## Trait implementations