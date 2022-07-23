# Memory Occupier

An interactive CLI Tool to Occupy Memory.

```sh
❯ ./mo 2048
PID: 77777
add <size>     : Occupy <size> MB of memory
release <size> : Release <size> MB of memory
quit           : Quit
Memory Occupied: 2048 MB
```

## Compile

You need `clang` (or `gcc`) and `make` to compile `mo`.

```sh
make
```

Then you can run `mo` by typing `./mo`.

## Usage

There are three commands in `mo`:

- `add <size>` (`a <size>`): Occupy `<size>` MB of memory.
- `release <size>` (`r <size>`): Release `<size>` MB of memory.
- `quit` (`q`): Quit `mo`.

After you add or release memory, `mo` will show you the current status of memory occupation.

You can also set the initial size of memory occupation by passing a number to it:

```sh
./mo 2048
```

This will occupy 2048 MB of memory at the beginning.
