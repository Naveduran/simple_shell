#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> /* for printf*/
#include <unistd.h>
#include <stdlib.h> /* */
#include <string.h> /* for strtok*/
#include <stddef.h>

/*execute a command with its entire path*/
int execute(char *string, char *environment[]);

char *tokenize(char *string);

#endif /* SHELL_H */
