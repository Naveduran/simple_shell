#include "shell.h"

/**
 * builtins_list - search for match and execute the associate builtin
 * @tokens: double pointer which first element is the string to match
 * Return: Returns the return of the function executed is there is a match,
 * otherwise returns -1.
 **/
int builtins_list(data_of_program *data)
{
	int iterator;
	builtins options[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{"cd", builtin_cd},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{"help", builtin_help},
		{NULL, NULL}
	};

/*walk through the structure*/
	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
/*if there is a match between the given command and a builtin,*/
		if (str_compare(options[iterator].builtin, data->command_name, 0))
		{
/*execute the function, and return the return value of the function*/
			return (options[iterator].function(data));
		}
/*if there is no match return -1 */
	}
	return (-1);
}
