#include "shell.h"
/**
 * builtin_exit - exit
 * @tokens: an array of the function and the arguments of the functions
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_exit(char *tokens[])
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
	free_array_of_pointers(tokens);
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
		_print("\n");
	}
	return (0);
}

/**
 * builtin_cd - change the current directory
 * @tokens: an array of the function and the arguments of the functions
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_cd(char *tokens[])
{
    int retvalue= 0, i = 0, home = 0, now = 0;
		char *homedir = NULL;
		char *homedirectory[] = {"$HOME", "~", "\0"};
		char *actualdir = NULL;
/* char *options[] = {"-L", "-P", "-e", "-@"}; */

/* set the home directory */
		while (environ[i])
		{
			if (str_compare("HOME=", environ[i], 5))
			{
				homedir = str_duplicate(environ[i] + 5);/* falta freezear */
                break;
			}
			i++;
		}
/* search for a coincidence to go to the home directory */
		if (tokens[1] == NULL)
		{
			printf("TOKENS[1] == NULL, ENTONCES CAMBIA EL PATH\n");
			retvalue = chdir(homedir);
			printf("retvalue = %d\n", retvalue);
			return (retvalue);
		}
		for (; homedirectory[i + 1]; i++)
		{
			home = str_compare(tokens[1], homedirectory[i], 0);
			if (home)
			{
/* change the directory to the home */
				return (chdir(homedir));
			}
		}
/* if the actual directory is the same just return*/
/**		if (str_compare("PWD=", environ[i], 4)) */
		now = str_compare(tokens[1], getcwd(actualdir, 30), 0);
		if (now)
			return (0);
		return (0);
}
