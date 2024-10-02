#ifndef COMMANDS_H
#define COMMANDS_H

int handle_builtin(char **args);
void execute_command(char **args);
void execute_background_command(char **args);

#endif
