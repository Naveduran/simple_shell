#include "shell.h"

/**
 * builtin_exit - exit
 * @tokens: an array of the function and the arguments of the functions
 * Return: zero if sucess, or other number if its declared in the arguments
 */

int builtin_exit(char *tokens[])
{
	if (tokens[1] != NULL)
		exit(atoi(tokens[1]));
	else
		exit(EXIT_SUCCESS);
}
/**
 * builtin_env - shows the environment where the shell runs
 * @tokens: an array of the function and the arguments of the functions
 * Return: zero if sucess, or other number if its declared in the arguments
 */

int builtin_env(char *tokens[] __attribute__((unused)))
{
	int iterator;

	for (iterator = 0; environ[iterator]; iterator++)
	{
		_print(environ[iterator]);
	}
	return (0);
}
