# `module Minilib.IO.Channel`

A Channel that can be used for the communication of threads.

# Types and aliases

## `namespace Minilib.IO.Channel`

### `type Channel a = unbox struct { ...fields... }`

A Channel that can be used for the communication of threads.

#### field `var : AsyncTask::Var::Var (Minilib.IO.Channel::ChannelData a)`

### `type ChannelData a = unbox struct { ...fields... }`

The channel data

#### field `deque : Minilib.Collection.Deque::Deque a`

#### field `closed : Std::Bool`

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.IO.Channel`

### `clear : Minilib.IO.Channel::Channel a -> Std::IO ()`

`channel.clear` clears the queue of the channel.

### `close : Minilib.IO.Channel::Channel a -> Std::IO ()`

`channel.close` closes a channel.
After close, `send()` will fail.

### `closed_error : Std::String`

An error message which is reported when the channel is closed.

### `is_closed : Minilib.IO.Channel::Channel a -> Std::IO Std::Bool`

`channel.is_closed` checks whether the channel is closed.

### `is_empty : Minilib.IO.Channel::Channel a -> Std::IO Std::Bool`

`channel.is_empty` checks whether the queue of the channel is empty.

### `make : Std::IO (Minilib.IO.Channel::Channel a)`

`Channel::make` creates a new channel.

### `recv : Minilib.IO.Channel::Channel a -> Std::IO::IOFail a`

`channel.recv` receives a data from the queue of the channel.
If the queue is empty, it waits until any data is sent, or the channel is closed.
If the channel is closed and the queue is empty, it throws `closed_error`.

### `send : a -> Minilib.IO.Channel::Channel a -> Std::IO::IOFail ()`

`channel.send(a)` sends a data to the queue of the channel.
If the channel is closed, it throws `closed_error`.

### `take_and_clear : Minilib.IO.Channel::Channel a -> Std::IO (Std::Iterator a)`

`channel.take_and_clear` takes all items away from the queue of the channel
and clears the queue.
This function can be used after the channel is closed.

### `try_recv : Minilib.IO.Channel::Channel a -> Std::IO::IOFail (Std::Option a)`

`channel.recv` tries to receive a data from a channel.
If there is no data, `none` is returned.
If the channel is closed and the queue is empty, it throws `closed_error`.

## `namespace Minilib.IO.Channel::Channel`

### `@var : Minilib.IO.Channel::Channel a -> AsyncTask::Var::Var (Minilib.IO.Channel::ChannelData a)`

Retrieves the field `var` from a value of `Channel`.

### `act_var : [f : Std::Functor] (AsyncTask::Var::Var (Minilib.IO.Channel::ChannelData a) -> f (AsyncTask::Var::Var (Minilib.IO.Channel::ChannelData a))) -> Minilib.IO.Channel::Channel a -> f (Minilib.IO.Channel::Channel a)`

Updates a value of `Channel` by applying a functorial action to field `var`.

### `mod_var : (AsyncTask::Var::Var (Minilib.IO.Channel::ChannelData a) -> AsyncTask::Var::Var (Minilib.IO.Channel::ChannelData a)) -> Minilib.IO.Channel::Channel a -> Minilib.IO.Channel::Channel a`

Updates a value of `Channel` by applying a function to field `var`.

### `set_var : AsyncTask::Var::Var (Minilib.IO.Channel::ChannelData a) -> Minilib.IO.Channel::Channel a -> Minilib.IO.Channel::Channel a`

Updates a value of `Channel` by setting field `var` to a specified one.

## `namespace Minilib.IO.Channel::ChannelData`

### `@closed : Minilib.IO.Channel::ChannelData a -> Std::Bool`

Retrieves the field `closed` from a value of `ChannelData`.

### `@deque : Minilib.IO.Channel::ChannelData a -> Minilib.Collection.Deque::Deque a`

Retrieves the field `deque` from a value of `ChannelData`.

### `act_closed : [f : Std::Functor] (Std::Bool -> f Std::Bool) -> Minilib.IO.Channel::ChannelData a -> f (Minilib.IO.Channel::ChannelData a)`

Updates a value of `ChannelData` by applying a functorial action to field `closed`.

### `act_deque : [f : Std::Functor] (Minilib.Collection.Deque::Deque a -> f (Minilib.Collection.Deque::Deque a)) -> Minilib.IO.Channel::ChannelData a -> f (Minilib.IO.Channel::ChannelData a)`

Updates a value of `ChannelData` by applying a functorial action to field `deque`.

### `mod_closed : (Std::Bool -> Std::Bool) -> Minilib.IO.Channel::ChannelData a -> Minilib.IO.Channel::ChannelData a`

Updates a value of `ChannelData` by applying a function to field `closed`.

### `mod_deque : (Minilib.Collection.Deque::Deque a -> Minilib.Collection.Deque::Deque a) -> Minilib.IO.Channel::ChannelData a -> Minilib.IO.Channel::ChannelData a`

Updates a value of `ChannelData` by applying a function to field `deque`.

### `set_closed : Std::Bool -> Minilib.IO.Channel::ChannelData a -> Minilib.IO.Channel::ChannelData a`

Updates a value of `ChannelData` by setting field `closed` to a specified one.

### `set_deque : Minilib.Collection.Deque::Deque a -> Minilib.IO.Channel::ChannelData a -> Minilib.IO.Channel::ChannelData a`

Updates a value of `ChannelData` by setting field `deque` to a specified one.