# Experimental Shell (XSH)

## Developed by:
- **Name:** Atah Habibi
- **Username:** cssc4466
- **Name:** Matthew Press
- **Username:** cssc4443

## Class Information:
- **Class:** CS 480, Summer 2024
- **Assignment:** Assignment #2, Experimental Shell (XSH)

## Filename:
- **Filename:** README.md

## File Manifest:
- `main.c` - Contains the main function to run the shell loop.
- `shell.c` - Contains the implementation of the shell functions.
- `shell.h` - Header file containing the declarations of the shell functions.
- `Makefile` - File to compile the program.
- `README.md` - This file, providing a basic description of the project and instructions.

## Compile Instructions:
1. Navigate to the `~/a2` directory.
2. Run `make` to compile the program:
    ```bash
    cd ~/a2
    make
    ```

## Operating Instructions:
1. Execute `./dsh` to start the shell:
    ```bash
    ./dsh
    ```
2. Enter commands in the format specified below:
    - Single command: `cssc0000% ls -la`
    - Command with arguments: `cssc0000% /usr/bin/echo printme`
    - Command with pipes: `cssc0000% ls -la | sort -fi`
    - Command with multiple pipes: `cssc0000% ls -la | sort -fi | grep .bashrc`
    - Exit the shell: `cssc0000% exit`

## Novel/Significant Design Decisions:
- Implemented basic command execution and handling of piped commands using `fork` and `execvp`.
- Included detailed error handling for failed command executions.
- Simplified the design to focus on core functionality as required by the assignment.

## Extra Features/Algorithms/Functionality:
- None beyond the requirements specified in the assignment.

## Known Deficiencies or Bugs:
- The shell does not handle background processes or signal handling.
- Limited to single arguments and basic piping without complex parsing.

## Lessons Learned:
- Gained a deeper understanding of process management and inter-process communication in Unix-like systems.
- Improved skills in handling user input and command parsing.
- Learned the importance of detailed error handling and user feedback in shell implementations.
