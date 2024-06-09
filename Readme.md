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


# Experimental Shell (XSH)

## Developed by:
- **Name:** Atah Habibi
- **Username:** cssc0000

## Description:
This is an experimental shell implementation named XSH. It supports launching new programs, handling pipes, and has a built-in `exit` function.

## Features:
- Print prompt and wait for user input.
- Execute commands with an optional single argument.
- Support for piping between commands.
- Built-in `exit` function to gracefully terminate the shell.

## Directory Structure:

~/a2
|-- main.c
|-- shell.c
|-- shell.h
|-- Makefile
|-- README.md


## Code:

### shell.h
```c
#ifndef SHELL_H
#define SHELL_H

void print_prompt();
char* read_input();
void execute_command(char *input);

#endif // SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

// MAIN.C

int main() {
    while (1) {
        print_prompt();
        char *input = read_input();
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }
        execute_command(input);
        free(input);
    }
    return 0;
}


//SHELL.C


#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void print_prompt() {
    printf("cssc0000%% ");  // Replace cssc0000 with your class account username
    fflush(stdout);
}

char* read_input() {
    char *input = NULL;
    size_t len = 0;
    getline(&input, &len, stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character
    return input;
}

void execute_command(char *input) {
    // Parse command
    char *args[100];
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Check for pipe
    int pipe_index = -1;
    for (int j = 0; j < i; j++) {
        if (strcmp(args[j], "|") == 0) {
            pipe_index = j;
            break;
        }
    }

    if (pipe_index != -1) {
        // Handle pipe
        args[pipe_index] = NULL;
        int fd[2];
        pipe(fd);

        pid_t pid1 = fork();
        if (pid1 == 0) {
            // Child process 1
            close(fd[0]);
            dup2(fd[1], STDOUT_FILENO);
            close(fd[1]);
            execvp(args[0], args);
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }

        pid_t pid2 = fork();
        if (pid2 == 0) {
            // Child process 2
            close(fd[1]);
            dup2(fd[0], STDIN_FILENO);
            close(fd[0]);
            execvp(args[pipe_index + 1], &args[pipe_index + 1]);
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }

        // Parent process
        close(fd[0]);
        close(fd[1]);
        waitpid(pid1, NULL, 0);
        waitpid(pid2, NULL, 0);
    } else {
        // No pipe, single command
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror("execvp failed");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            waitpid(pid, NULL, 0);
        }
    }
}


//MAKE FILE

CC=gcc
CFLAGS=-Wall -g

all: dsh

dsh: main.o shell.o
	$(CC) $(CFLAGS) -o dsh main.o shell.o

main.o: main.c shell.h
	$(CC) $(CFLAGS) -c main.c

shell.o: shell.c shell.h
	$(CC) $(CFLAGS) -c shell.c

clean:
	rm -f *.o dsh





