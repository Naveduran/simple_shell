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

/************* MAIN FUNCTIONS *************/

/* brings the entire environment to be used inside this program*/
extern char **environ;

/* separate the string in tokens using a designed delimiter*/
char **tokenize(char *string, char **tokens, char *program);

/* creates a pointer to a part of a string*/
char *_strtok(char *line, char *delim);

/* execute a command with its entire path*/
int execute(char *tokens[], char *program);

/* if match a builtin, executes it */
int builtins_structure(char *tokens[]);

/* creates an array of the path directories */
char **tokenize_path();

/* search for program in path */
char *find_program(char *function_name);

/* frees the memory for directories */
void free_array_of_pointers(char **directories);


/************* STRUCTURES **************/

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


/************** BUILTINS **************/

/* close the shell*/
int builtin_exit(char *tokens[]);

/* shows the environment where the shell runs*/
int builtin_env(char *tokens[]);

/* change the current directory */
int builtin_cd(char *tokens[]);

/************** PRINTING FUNCTIONS **************/

/* prints a string in the standar output*/
int _print(char *string);

/* prints a string in the standar error*/
int _printe(char *string);

/* prints a string in the standar error*/
int _print_error(int errorcode, int exec_counter, char *tokens[], char *prog);


/************** HELPERS **************/

/* Counts the number of characters of a string */
int str_length(char *string);

/* Duplicates an string */
char *str_duplicate(char *string);

/* Compares two strings*/
int str_compare(char *string1, char *string2, int number);

/* concatenates two strings */
char *str_concat(char *string1, char *string2);

/* cast from int to string*/
void long_to_string(long number, char *string, int base);

/* reverse a string */
void str_reverse(char *string);

#endif /* SHELL_H */
