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
#include <sys/stat.h> /*for use of stat function*/

extern char **environ;

int _print(char *string);

/*separate the string in tokens using a designed delimiter*/
char **tokenize(char *string, char *tokens[]);

/*2_execute.c a command with its entire path*/
int execute(char *tokens[]);

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

/* shows the environment where the shell runs*/
int builtin_env(char *tokens[]);

/* find a program in path */
char *find_program(char *function_name);

/* return array of path directories */
char **tokenize_path();

/* frees the memory for directories */
void free_array_of_pointers(char **directories);


/* Counts the number of characters of a string */
int str_length(char *string);

/* Duplicates an string */
char *str_duplicate(char *string);

/* Compares two strings*/
int str_compare(char *string1, char *string2, int number);

/* concatenates two strings */
char *str_concat(char *string1, char *string2);

#endif /* SHELL_H */
