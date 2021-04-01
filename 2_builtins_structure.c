#include "shell.h"
/**
 * builtins_structure - search for match and execute the associate builtin
 * @command: the character to match
 * @position: the position given
 * Return: Returns the return of the function executed is there is a match.
 * Otherwise returns NULL
 **/

int (*builtins_structure(const char *command, int position))(va_list)
{
	int iterator;
	spc_t options[] = {
/*{char * builtin, int (*function)(va_list)};*/
		{"exit", builtin_exit},
		{"env", builtin_env},
		{NULL, NULL}
	};
/*walk trhough the structure*/
	for (iterator = 0; options[iterator].builtin != '\0'; iterator++)
/*if there is a match between the given command and a builtin,*/
		if (options[iterator].builtin[0] == command[position])
/*execute the function, and return the return value of the function*/
		{
			return (options[iterator].function);
		}
	return (NULL);
}
