#ifndef SHELL_H
#define SHELL_H

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
 * typedef struct - struct for the program's data
 * @tokens: pointer to the tokenized array of strings
 * @env: pointer to a copy of the array of environment variables
 * in which the program is executed
 * @program_name: pointer to the name of the executable program
 * @exec_counter: number of times an input line have been sent to the program.
 * @input_line: pointer to the string got from the getline function.
 * @command_name: pointer to the name of the command requested.
 */
typedef struct data_of_program
{
	char *program_name;
	int exec_counter;
	char *input_line;
	char *command_name;
	char **tokens;
	char **env;
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

/* */
void inicialize_data(data_of_program *data, char *argv[], char *env[]);

/* Makes the infinite loop that shows the prompt*/
void sisifo(char *prompt, int is_interactive,data_of_program *data);

/* Print the prompt in a new line */
void handle_ctrl_c(int opr UNUSED);

/* read one line of the standar input*/
int _getline(char **lineptr);

/* */
int expansions(data_of_program *data);

/* Separate the string in tokens using a designed delimiter */
void tokenize(data_of_program *data);

/* Creates a pointer to a part of a string */
char *_strtok(char *line, char *delim);

/* Execute a command with its entire path */
int execute(data_of_program *data);

/* If match a builtin, executes it */
int builtins_list(data_of_program *data);

/* Creates an array of the path directories */
char **tokenize_path(data_of_program *data);

/* Search for program in path */
void find_program(data_of_program *data);


/************** HELPERS FOR MEMORY MANAGEMENT **************/

/* Frees the memory for directories */
void free_array_of_pointers(char **directories);

/* */
void free_data(data_of_program *data);

/* */
void free_data_all(data_of_program *data);


/************** BUILTINS **************/

/* Close the shell */
int builtin_exit(data_of_program *data);

/* Shows the environment where the shell runs */
int builtin_env(data_of_program *data);

/* Change the current directory */
int builtin_cd(data_of_program *data);

/* */
int builtin_set_env(data_of_program *data);

/* */
int builtin_unset_env(data_of_program *data);

/**/
int builtin_help(data_of_program *data);


/************** HELPERS FOR ENVIRONMENT VARIABLES MANAGEMENT **************/

/* */
char *env_get_key(char *name, data_of_program *data);

/* */
int env_set_key(char *key, char *value, data_of_program *data);

/* */
int env_remove_key(char *key, data_of_program *data);


/************** HELPERS FOR PRINTING **************/

/* Prints a string in the standar output */
int _print(char *string);

/* Prints a string in the standar error */
int _printe(char *string);

/* Prints a string in the standar error */
int _print_error(int errorcode, data_of_program *data);


/************** HELPERS FOR STRINGS MANAGEMENT **************/

/* Counts the number of characters of a string */
int str_length(char *string);

/* Duplicates an string */
char *str_duplicate(char *string);

/* Compares two strings */
int str_compare(char *string1, char *string2, int number);

/* Concatenates two strings */
char *str_concat(char *string1, char *string2);

/* Reverse a string */
void str_reverse(char *string);

/* Cast from int to string */
void long_to_string(long number, char *string, int base);

#endif /* SHELL_H */
