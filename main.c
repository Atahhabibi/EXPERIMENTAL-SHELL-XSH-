#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

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
