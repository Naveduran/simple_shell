#ifndef SHELL_H
#define SHELL_H

/************* LIBRARIES **************/

#include <stdio.h> /* for printf*/
#include <unistd.h> /* for fork, execve*/
#include <stdlib.h>
#include <string.h> /* for strtok*/
#include <stddef.h>
#include <errno.h> /* for errno and perror */
#include <sys/types.h> /* for type pid */
#include <sys/wait.h> /* for wait */
#include <sys/stat.h> /* for use of stat function */
#include <signal.h> /* for signal management */

/************* MACROS **************/

#include "macros.h" /* for msg help and prompt */

/************* STRUCTURES **************/

/**
 * struct info- struct for the program's data
 * @program_name: the name of the executable
 * @exec_counter: number of excecuted comands
 * @input_line: pointer to the input read for _getline
 * @command_name: pointer to the first command typed by the user
 * @tokens: pointer to array of tokenized input
 * @env: copy of the environ
 * @alias_list: array of pointers with aliases.
 * @file: the file used to store the history
 * @pre_grep: number of lines in the previous history
 * @new_history: an array to save the commands written in the command line.
 */
typedef struct info
{
	char *program_name;
	int exec_counter;
	char *input_line;
	char *command_name;
	char **tokens;
	char **env;
	char **alias_list;
	FILE *file;
	int pre_grep;
	char **new_history;
} data_of_program;

/**
 * struct builtins - struct for the builtins
 * @builtin: the name of the builtin
 * @function: the associated function to be called for each builtin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;

/************* MAIN FUNCTIONS *************/

/* Inicialize the struct with the info of the program */
/* Included in file: shell.c */
void inicialize_data(data_of_program *data, char *argv[], char *env[]);

/* Makes the infinite loop that shows the prompt*/
/* Included in file: shell.c */
int sisifo(char *prompt, int is_interactive, data_of_program *data);

/* Print the prompt in a new line */
/* Included in file: shell.c */
void handle_ctrl_c(int opr UNUSED);

/* Read one line of the standar input*/
/* Included in file: _getline.c*/
int _getline(char **lineptr);

/* */
/* Included in file: expansions.c */
int expansions(data_of_program *data);

/* Separate the string in tokens using a designed delimiter */
/* Included in file: tokenize.c */
void tokenize(data_of_program *data);

/* Creates a pointer to a part of a string */
/* Included in file: str_tok.c */
char *_strtok(char *line, char *delim);

/* Execute a command with its entire path */
/* Included in file: execute.c */
int execute(data_of_program *data);

/* If match a builtin, executes it */
/* Included in file: builtins_list.c */
int builtins_list(data_of_program *data);

/* Creates an array of the path directories */
/* Included in file: XXXXX.c */
char **tokenize_path(data_of_program *data);

/* Search for program in path */
/* Included in file: XXXXXX.c */
int find_program(data_of_program *data);

/************** HELPERS FOR MEMORY MANAGEMENT **************/

/* Frees the memory for directories */
/* Included in file: helpers_free.c */
void free_array_of_pointers(char **directories);

/* Free the fields needed each loop */
/* Included in file: helpers_free.c */
void free_data(data_of_program *data);

/* Free all field of the data */
/* Included in file: helpers_free.c */
void free_data_all(data_of_program *data);

/************** BUILTINS **************/

/* Close the shell */
/* Included in file: XXXXX.c */
int builtin_exit(data_of_program *data);

/* Shows the environment where the shell runs */
/* Included in file: shell.c */
int builtin_env(data_of_program *data);

/* Change the current directory */
/* Included in file: shell.c */
int builtin_cd(data_of_program *data);

/* */
/* Included in file: shell.c */
int builtin_set_env(data_of_program *data);

/* */
/* Included in file: shell.c */
int builtin_unset_env(data_of_program *data);

/**/
/* Included in file: shell.c */
int builtin_help(data_of_program *data);

/**/
/* Included in file: shell.c */
int builtin_alias(data_of_program *data);

/**/
/* Included in file: history.c */
int builtin_history(data_of_program *data);

/************** HELPERS FOR ENVIRONMENT VARIABLES MANAGEMENT **************/

/* Gets the value of an environment variable */
/* Included in file: env_management.c */
char *env_get_key(char *name, data_of_program *data);

/* Overwrite the value of the environment variable */
/* Included in file: env_management.c */
int env_set_key(char *key, char *value, data_of_program *data);

/* Remove a key from the environment */
/* Included in file: env_management.c */
int env_remove_key(char *key, data_of_program *data);

/* prints the current environ */
/* Included in file: env_management.c */
void print_environ(data_of_program *data);

/************** HELPERS FOR PRINTING **************/

/* Prints a string in the standar output */
/* Included in file: shell.c */
int _print(char *string);

/* Prints a string in the standar error */
/* Included in file: shell.c */
int _printe(char *string);

/* Prints a string in the standar error */
/* Included in file: shell.c */
int _print_error(int errorcode, data_of_program *data);

/************** HELPERS FOR STRINGS MANAGEMENT **************/

/* Counts the number of characters of a string */
/* Included in file: shell.c */
int str_length(char *string);

/* Duplicates an string */
/* Included in file: shell.c */
char *str_duplicate(char *string);

/* Compares two strings */
/* Included in file: shell.c */
int str_compare(char *string1, char *string2, int number);

/* Concatenates two strings */
/* Included in file: shell.c */
char *str_concat(char *string1, char *string2);

/* Reverse a string */
/* Included in file: shell.c */
void str_reverse(char *string);

/* Cast from int to string */
/* Included in file: helpers_numbers.c */
void long_to_string(long number, char *string, int base);

/* convert an string in to a number */
/* Included in file: helpers_numbers.c */
int _atoi(char *s);

/* count the coincidences of character in string */
/* Included in file: helpers_numbers.c */
int count_characters(char *string, char *character);

/* concatenates strings to expand the input line */
/* Included in file: expansions.c */
void concat_exp(data_of_program *data, char *delim, char *exp, int i, int l);

/************** HELPERS FOR ALIASES **************/

/* print the list of alias */
/* Included in file:  */
int print_alias(data_of_program *data, char *alias);

/* get the alias name */
/* Included in file:  */
char *get_alias(data_of_program *data, char *alias);

/* set the alias name */
/* Included in file:  */
int set_alias(char *alias_string, data_of_program *data);


/************** HELPERS FOR HISTORY **************/

/*  */
/* Included in file: */
int read_history(data_of_program *data);

/* */
/* Included in file:  */
int add_to_history(data_of_program *data);

/*  */
/* Included in file:  */
int save_history(data_of_program *data);

#endif /* SHELL_H */
