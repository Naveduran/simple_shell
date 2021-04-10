#include "shell.h"

/**
 * builtins_structure - search for match and execute the associate builtin
 * @tokens: double pointer which first element is the string to match
 * Return: Returns the return of the function executed is there is a match,
 * otherwise returns -1.
 **/
int builtins_structure(char *tokens[])
{
	int iterator, equal;
	builtins options[] = {
		{"env", builtin_env},
		{NULL, NULL}
	};

/*walk through the structure*/
	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
/*if there is a match between the given command and a builtin,*/
		equal = str_compare(options[iterator].builtin, tokens[0], 0);
		if (equal)
/*execute the function, and return the return value of the function*/
		{
			return (options[iterator].function(tokens));
		}
/*if there is no match return -1 */
	}
	return (-1);
}
