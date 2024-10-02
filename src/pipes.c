#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "pipes.h"
#include "utils.h"
#include "redirection.h"

void handle_pipes(char *command) {
    char *commands[MAX_ARGS];
    int pipefd[2], fd = 0;

    // Split the commands by the pipe symbol "|"
    int i = 0;
    commands[i] = strsep(&command, "|");
    while (commands[i] != NULL) {
        i++;
        commands[i] = strsep(&command, "|");
    }

    for (int j = 0; j < i; j++) {
        pipe(pipefd);  // Create a pipe

        if (fork() == 0) {
            // Child process
            dup2(fd, 0);  // Read input from the previous pipe
            if (j + 1 < i) dup2(pipefd[1], 1);  // Write output to the next pipe

            close(pipefd[0]);

            // Parse and execute the command
            char *args[MAX_ARGS];
            parse_command(commands[j], args);
            handle_redirection(args);  // Handle redirection if present
            execvp(args[0], args);  // Execute the command
            perror("execvp failed");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(NULL);  // Wait for the child process to finish
            close(pipefd[1]);
            fd = pipefd[0];  // Save input for the next command
        }
    }
}
