#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> /* for printf*/
#include <unistd.h> /* for fork, execve*/
#include <stdlib.h>
#include <string.h> /* for strtok*/
#include <stddef.h>
#include <errno.h> /*for errno and perror*/
#include <sys/types.h> /*for type pid*/
#include <sys/wait.h> /*for wait*/

/*1_tokenize.c*/
char **tokenize(char *string, char *tokens[]);

/*2_execute.c a command with its entire path*/
int execute(char *tokens[], char *environment[]);

/* 2_builtins_structure.c search for match between the first token
/*                         with the builtins and execute the builtin */
int builtins_structure(char *tokens[]);

/**
 * struct builtins - struct for the builtins
 * @builtin: the name of the builtin
 * @function: the associated function to be called for each builtin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(char *tokens[]);
} builtins;

int builtin_exit(char *tokens[]);

/* util.c */
int str_length(char *string);

char *str_duplicate(char *string);

#endif /* SHELL_H */
