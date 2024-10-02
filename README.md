# Custom Shell

This is a simple custom shell built in C that supports various basic Unix commands, input/output redirection, pipes, and background process execution. It is designed to mimic the functionality of a basic Linux shell while being modular and extendable.

## Features

- **Built-in commands**:
  - `cd` - Change directory.
  - `exit` - Exit the shell.

- **External commands**: 
  - Execute most Unix/Linux commands using `execvp`.
  
- **Piping**: 
  - Supports piping (`|`) between commands.
  
- **Input/output redirection**:
  - Supports redirection of input (`<`) and output (`>`, `>>`).

- **Background processes**:
  - Execute commands in the background using `&`.

## Directory Structure

```bash
src/
├── shell.c          # Main entry point for the shell.
├── commands.c       # Handling built-in and external commands.
├── pipes.c          # Implementation for handling pipes between commands.
├── redirection.c    # Handling input/output redirection.
├── utils.c          # Utility functions used throughout the shell.
├── commands.h       # Header for commands.c.
├── pipes.h          # Header for pipes.c.
├── redirection.h    # Header for redirection.c.
├── utils.h          # Header for utils.c.

```

## Compiling The Shell

```bash
gcc -Wall -o shell src/shell.c src/commands.c src/redirection.c src/pipes.c src/utils.c
```

## Running The Shell

```bash
./shell
```
