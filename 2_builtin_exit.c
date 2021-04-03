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
