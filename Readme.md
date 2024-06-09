Experimental Shell (XSH)
========================

Developed by:
- Name: ATAH HABIBI (username)

Description:
This is an experimental shell implementation named XSH. It supports launching new programs, handling pipes, and has a built-in exit function.

Features:
- Print prompt and wait for user input.
- Execute commands with optional single argument.
- Support for piping between commands.
- Built-in exit function to gracefully terminate the shell.

How to Compile:
1. Navigate to the `~/a2` directory.
2. Run `make` to compile the program.

How to Run:
1. Execute `./dsh` to start the shell.
2. Enter commands in the format specified in the assignment.
3. Type `exit` to terminate the shell.

Contributors:
- Name: MATTEW (username)



## Code:

### shell.h
```c
#ifndef SHELL_H
#define SHELL_H

void print_prompt();
char* read_input();
void execute_command(char *input);

#endif // SHELL_H
