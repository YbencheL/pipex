# pipex

`pipex` is a C project that recreates the behavior of a simple shell pipeline. It reads from an input file, runs two commands in sequence, and writes the result to an output file.

It is designed to behave like:

```sh
< infile cmd1 | cmd2 > outfile
```

## Requirements

- A Unix-like operating system
- `cc` or another C compiler
- `make`

## Build

Clone the repository and compile the program:

```sh
git clone https://github.com/YbencheL/pipex.git
cd pipex
make
```

This creates the `pipex` executable.

## Usage

```sh
./pipex infile "cmd1" "cmd2" outfile
```

For example:

```sh
./pipex input.txt "grep hello" "wc -l" output.txt
```

This runs `grep hello` with `input.txt` as its input, sends its output to `wc -l`, and writes the final result to `output.txt`.

Commands are looked up using the `PATH` environment variable. You can also provide a command path directly.

## Makefile commands

- `make` — compile the project
- `make clean` — remove object files
- `make fclean` — remove object files and the executable
- `make re` — clean and rebuild

## Project concepts

This project works with several Unix system calls and concepts, including:

- Pipes and file descriptors
- Processes with `fork()`
- Command execution with `execve()`
- Input/output redirection with `dup2()`
- Waiting for child processes

## Project structure

- `pipex.c` — program entry point and process/pipeline setup
- `utils.c` — command lookup and execution helpers
- `pipex.h` — shared declarations
- `ft_*.c` — supporting string and formatted-output utilities
- `Makefile` — build rules

## License

No license is currently specified for this repository.
