#include "shell.h"

/**
 * builtin_exit - exit
 * @tokens: an array of the function and the arguments of the functions
 * @string: string to be freed if exit succesfull
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_exit(char *tokens[], char *string)
{
	int i;

	if (tokens[1] != NULL)
	{/*if exists arg for exit, check if is a number*/
		for (i = 0; tokens[1][i]; i++)
			if (tokens[1][i] < '0' || tokens[1][i] > '9')
			{/*if is not a number*/
				errno = 2;
				return (2);
			}
			errno = atoi(tokens[1]);
	}
	free(string);
	free(tokens);
	exit(errno);
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
