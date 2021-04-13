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

	if (data->tokens[1] == NULL)
	{
		for (iterator = 0; data->env[iterator]; iterator++)
		{
			_print(data->env[iterator]);
			_print("\n");
		}
	}
	else{
		errno = 2;
		perror(data->command_name);
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

	while (data->env[i])/* find and duplicate the home directory */
	{
		if (str_compare("HOME=", data->env[i], 5))
		{
			homedir = str_duplicate(data->env[i] + 5); /* falta freezear */
			break;
		}
		i++;
	}
	if (data->tokens[1] == NULL) /* must go to the home directory? */
		return (env_set_key("HOME", homedir, data));
	for (; homedirectory[i + 1]; i++) /* must go to the home directory? */
	{
		home = str_compare(data->tokens[1], homedirectory[i], 0);
		if (home)
			return (env_set_key("HOME", homedir, data));
	}
/* if the actual directory is the same just return*/
	now = str_compare(data->tokens[1], env_get_key(actualdir, data), 0);
	if (now)
		return (0);
	return (env_set_key("HOME", data->tokens[1], data));
}

/**
 * builtin_set_env - ..
 * @data: struct for the program's data
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
 * builtin_unset_env - ..
 * @data: struct for the program's data'
 * Return: ..
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


/**
 * builtin_help - shows the environment where the shell runs
 * @tokens: an array of the function and the arguments of the functions
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_help(data_of_program *data)
{
	int i;

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
	builtins help_builds[] = {
		/*{"exit", builtin_exit_help},
		{"env", builtin_env},*/
		{"cd", builtin_cd_help},
		/*{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},*/
		{NULL, NULL}
	};

	/*checks for coincidence in the list */
	for (i = 0; help_builds[i].builtin != NULL; i++)
	{
/*if there is a match between the given command and a builtin,*/
		if ( str_compare(help_builds[i].builtin, data->tokens[1], 0))
		{
/*execute the function, and return the return value of the function*/
			return (help_builds[i].function(data));
		}

	}
	/*if there is no match, print error and return -1 */
	errno = EINVAL;
	perror(data->command_name);
	return (0);
}

