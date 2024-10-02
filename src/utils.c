#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

// Function to read user input
void read_command(char *command) {
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = 0;  // Remove the newline character
}

// Function to parse the input into command and arguments
void parse_command(char *command, char **args) {
    for (int i = 0; i < MAX_ARGS; i++) {
        args[i] = strsep(&command, " ");
        if (args[i] == NULL) break;
    }
}

// Function to check if a command should run in the background
int is_background(char **args) {
    int i = 0;
    while (args[i] != NULL) {
        if (strcmp(args[i], "&") == 0) {
            args[i] = NULL;  // Remove the '&' symbol
            return 1;
        }
        i++;
    }
    return 0;
}
