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

/*separate the string in tokens using a designed delimiter*/
char **tokenize(char *string, char *tokens[]);

/*2_execute.c a command with its entire path*/
int execute(char *tokens[], char *environment[]);

/* if match a builtin, executes it */
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

/* close the shell*/
int builtin_exit(char *tokens[]);

/* Counts the number of characters of a string */
int str_length(char *string);

/* Duplicates an string */
char *str_duplicate(char *string);

/* Compares two strings*/
int string_compare(char *string1, char *string2, int number);

#endif /* SHELL_H */
