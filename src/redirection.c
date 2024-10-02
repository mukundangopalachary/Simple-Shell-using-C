#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "redirection.h"

void handle_redirection(char **args) {
    int i = 0;
    int fd;
    while (args[i] != NULL) {
        if (strcmp(args[i], ">") == 0) {
            // Output redirection
            fd = open(args[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
            if (fd < 0) perror("open failed");
            dup2(fd, STDOUT_FILENO);
            close(fd);
            args[i] = NULL;  // Remove the redirection part
        } else if (strcmp(args[i], "<") == 0) {
            // Input redirection
            fd = open(args[i + 1], O_RDONLY);
            if (fd < 0) perror("open failed");
            dup2(fd, STDIN_FILENO);
            close(fd);
            args[i] = NULL;
        }
        i++;
    }
}
