#include "shell.h"
/**
 * builtins_structure - search for match and execute the associate builtin
 * @command: the character to match
 * @position: the position given
 * Return: Returns the return of the function executed is there is a match.
 * Otherwise returns NULL
 **/

int builtins_structure(token_node **tokens)
{
	int iterator;
	builtins options[] = {
		{"exit", builtin_exit},
		{NULL, NULL}
	};

/*walk trhough the structure*/
	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
/*if there is a match between the given command and a builtin,*/
		if (options[iterator].builtin == (*tokens)->token)
/*execute the function, and return the return value of the function*/
			return (options[iterator].function(tokens));
/*if there is no match return -1 */
	return (0);
}
