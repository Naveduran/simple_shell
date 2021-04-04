#include "shell.h"

/**
 * builtin_exit - exit
 * @tokens: an array of the function and the arguments of the functions
 * Return: zero if sucess, or other number if its declared in the arguments
 */

int builtin_exit(char *tokens[])
{
	exit(0);
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
        printf("%s\n", environ[iterator]);
    }
	return (0);
}
