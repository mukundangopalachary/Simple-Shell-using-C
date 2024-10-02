#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"
#include "redirection.h"
#include "pipes.h"
#include "utils.h"

#define MAX_COMMAND_LENGTH 1024

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    
    while (1) {
        printf("myshell> ");
        read_command(command);

        if (strcmp(command, "exit") == 0) break; // Exit shell on "exit"

        if (strstr(command, "|") != NULL) {
            handle_pipes(command);  // Handle pipe commands
        } else {
            parse_command(command, args);

            if (handle_builtin(args)) continue;  // Handle built-in commands like "cd"

            int background = is_background(args); // Check if it's a background process
            
            if (!background) {
                execute_command(args);  // Execute external commands
            } else {
                execute_background_command(args);  // Execute background commands
            }
        }
    }

    return 0;
}
