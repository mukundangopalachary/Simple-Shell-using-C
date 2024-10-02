#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include<string.h>
#include "commands.h"
#include "redirection.h"
#include "utils.h"

int handle_builtin(char **args) {
    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL || chdir(args[1]) != 0) {
            perror("cd failed");
        }
        return 1;  // Built-in command executed
    }
    return 0;  // Not a built-in command
}

void execute_command(char **args) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        handle_redirection(args);  // Handle I/O redirection

        if (execvp(args[0], args) == -1) {
            perror("execvp failed");
        }
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);  // Parent waits for the child process to complete
    }
}

void execute_background_command(char **args) {
    if (fork() == 0) {
        handle_redirection(args);
        execvp(args[0], args);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    }
    // Parent does not wait for the child (background execution)
}
