#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void print_prompt() {
    printf("cssc0000%% ");
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
