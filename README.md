# MiniRedis

A small in-memory key-value store with a command-line interface, written in C++. It is built on `ministl`, a mini STL with a custom hashmap.

## Project layout

```
MiniRedis/
├── ministl/          # Custom template library (vector, hashmap, hash, ListNode)
│   └── tests/        # Tests for ministl
└── miniredis/        # The database
    ├── main.cpp            # REPL: reads commands from stdin
    ├── key_value_store.*   # Stores keys and values using ministl::hashmap
    ├── command_parser.*    # Splits an input line into words
    └── command_executor.*  # Runs a command against the store
```

## Build and run

From the `miniredis` folder:

```
g++ -std=c++17 main.cpp -o main
./main
```

`main.cpp` includes the other `.cpp` files, so this single command builds the whole program.

## Commands

Command names are case-sensitive and lowercase.

| Command | Arguments | Result |
|---|---|---|
| `set` | `key value` | Stores the value. Prints nothing. |
| `get` | `key` | Prints the value, or nothing if the key is missing. |
| `del` | `key` | Removes the key. Prints nothing. |
| `exists` | `key` | Prints `key : value` if the key exists, or nothing if not. |

Any other input prints `Error: Unknown Command`. Blank lines are ignored.

Example session:

```
> set name bob
> get name
bob
> exists name
name : bob
> del name
> get name

```
