#ifndef UTILS_H
#define UTILS_H

#define MAX_ARGS 64
#define MAX_COMMAND_LENGTH 1024

void read_command(char *command);
void parse_command(char *command, char **args);
int is_background(char **args);

#endif
