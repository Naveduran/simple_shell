#include "shell.h"
/**
 * builtin_exit - exit
 * @tokens: an array of the function and the arguments of the functions
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_exit(data_of_program *data)
{
	int i;

	if (data->tokens[1] != NULL)
	{/*if exists arg for exit, check if is a number*/
		for (i = 0; data->tokens[1][i]; i++)
			if (data->tokens[1][i] < '0' || data->tokens[1][i] > '9')
			{/*if is not a number*/
				errno = 2;
				env_set_key("HOLA", "Como estas bebe?", data);
				return (2);
			}
			errno = atoi(data->tokens[1]);
	}
	free_data_all(data);
	exit(errno);
}

/**
 * builtin_env - shows the environment where the shell runs
 * @tokens: an array of the function and the arguments of the functions
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_env(data_of_program *data)
{
	int iterator;
	for (iterator = 0; data->env[iterator]; iterator++)
	{
		_print(data->env[iterator]);
		_print("\n");
	}
	return (0);
}

/**
 * builtin_cd - change the current directory
 * @tokens: an array of the function and the arguments of the functions
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_cd(data_of_program *data)
{
    int retvalue= 0, i = 0, home = 0, now = 0;
		char *homedir = NULL;
		char *homedirectory[] = {"$HOME", "~", "\0"};
		char *actualdir = NULL;
/* char *options[] = {"-L", "-P", "-e", "-@"}; */

/* set the home directory */
		while (data->env[i])
		{
			if (str_compare("HOME=", data->env[i], 5))
			{
				homedir = str_duplicate(data->env[i] + 5);/* falta freezear */
                break;
			}
			i++;
		}
/* search for a coincidence to go to the home directory */
		if (data->tokens[1] == NULL)
		{
			printf("TOKENS[1] == NULL, ENTONCES CAMBIA EL PATH\n");
			retvalue = chdir(homedir);
			printf("retvalue = %d\n", retvalue);
			return (retvalue);
		}
		for (; homedirectory[i + 1]; i++)
		{
			home = str_compare(data->tokens[1], homedirectory[i], 0);
			if (home)
			{
/* change the directory to the home */
				return (chdir(homedir));
			}
		}
/* if the actual directory is the same just return*/
/**		if (str_compare("PWD=", environ[i], 4)) */
		now = str_compare(data->tokens[1], getcwd(actualdir, 30), 0);
		if (now)
			return (0);
		return (0);
}

/**
 * builtin_env - shows the environment where the shell runs
 * @tokens: an array of the function and the arguments of the functions
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_set_env(data_of_program *data)
{
	/* validate args */
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
	{
		errno = EINVAL;
		perror(data->command_name);
		return(5);
	}
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return(5);
	}
	env_set_key(data->tokens[1], data->tokens[2], data);

	return (0);
}

/**
 * builtin_env - shows the environment where the shell runs
 * @tokens: an array of the function and the arguments of the functions
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_unset_env(data_of_program *data)
{
	/* validate args */
	if (data->tokens[1] == NULL)
	{
		errno = EINVAL;
		perror(data->command_name);
		return(5);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return(5);
	}
	env_remove_key(data->tokens[1], data);

	return (0);
}
