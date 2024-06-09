#ifndef SHELL_H
#define SHELL_H

// Function to print the shell prompt
void print_prompt();

// Function to read the user input
char* read_input();

// Function to execute the command entered by the user
void execute_command(char *input);

#endif // SHELL_H
