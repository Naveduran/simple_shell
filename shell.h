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
#define PROMPT_MSG "dali<3 "
#define UNUSED __attribute__((unused))


/************* STRUCTURES **************/


/**
 * typedef struct - struct for the data of the program
 * @tokens: the name of the builtin
 * @env: the associated function to be called for each builtin
 * @program_name: name of the program
 * @exec_counter: counter of commands executed.
 * @input_line: string of the getline function.
 * @command_name: first word that user has tiping.
 */
typedef struct data_of_program
{
	char **tokens;
	char **env;
	char *program_name;
	int exec_counter;
	char *input_line;
	char *command_name;
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

/* print the prompt in a new line */
void handle_ctrl_c(int);

/* separate the string in tokens using a designed delimiter*/
void tokenize(data_of_program *data);

/* creates a pointer to a part of a string*/
char *_strtok(char *line, char *delim);

/* execute a command with its entire path*/
int execute(data_of_program *data);

/* if match a builtin, executes it */
int builtins_list(data_of_program *data);

/* creates an array of the path directories */
char **tokenize_path(data_of_program *data);

/* search for program in path */
void find_program(data_of_program *data);

/* frees the memory for directories */
void free_array_of_pointers(char **directories);


/************** BUILTINS **************/

/* close the shell*/
int builtin_exit(data_of_program *data);

/* shows the environment where the shell runs*/
int builtin_env(data_of_program *data);

/* change the current directory */
int builtin_cd(data_of_program *data);

/************** PRINTING FUNCTIONS **************/

/* prints a string in the standar output*/
int _print(char *string);

/* prints a string in the standar error*/
int _printe(char *string);

/* prints a string in the standar error*/
int _print_error(int errorcode, data_of_program *data);


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








void free_data(data_of_program *data);
void free_data_all(data_of_program *data);

char *env_get_key(char *name, data_of_program *data);
char *env_set_key(char *key, char *value, data_of_program *data);
int env_remove_key(char *key, data_of_program *data);

int builtin_set_env(data_of_program *data);
int builtin_unset_env(data_of_program *data);

#endif /* SHELL_H */
