#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"


// ## Developed by:
//- **Name:** Atah Habibi
//- **Username:** cssc4466
//- **Name:** Matthew Press
//- **Username:** cssc4443

// Main function to run the shell loop
int main() {
    while (1) {
        // Print the shell prompt
        print_prompt();
        
        // Read the user input
        char *input = read_input();
        
        // If the user types "exit", break the loop and exit the shell
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }
        
        // Execute the command entered by the user
        execute_command(input);
        free(input);
    }
    return 0;
}
