#include "shell.h"
/**
 * builtins_structure - search for match and execute the associate builtin
 * @tokens: double pointer which first element is the string to match
 * Return: Returns the return of the function executed is there is a match,
 * otherwise returns NULL.
 **/

int builtins_structure(char *tokens[])
{
	int iterator;
	builtins options[] = {
		{"exit", builtin_exit(tokens)},
		{NULL, NULL}
	};

/*walk through the structure*/
	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
/*if there is a match between the given command and a builtin,*/
		if (options[iterator].builtin == tokens[0])
/*execute the function, and return the return value of the function*/
		{
			printf("El token coincide con la builtin!\n");
			return (options[iterator].function);
		}
/*if there is no match return -1 */
	}
	printf("Ya recorrí las builtins y no encontré match\n");
	return (0);
	}
}
