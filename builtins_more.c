#include "shell.h"

/**
 * builtin_exit - exit
 * @data: struct for the program's data
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
 * builtin_cd - change the current directory
 * @UNUSED: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_cd(data_of_program *data UNUSED)
{
	return (0);
}

/**
 * builtin_help - shows the environment where the shell runs
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_help(data_of_program *data)
{
	int i, length = 0;
	char *mensajes[6] = {NULL};

	/* validate args */
	if (data->tokens[1] == NULL)
	{
		_print(HELP_MSG);
		return (1);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	mensajes[0] = HELP_CD_MSG;
	mensajes[1] = HELP_EXIT_MSG;
	mensajes[2] = HELP_ENV_MSG;
	mensajes[3] = HELP_SETENV_MSG;
	mensajes[4] = HELP_UNSETENV_MSG;
	mensajes[5] = HELP_MSG;

	for (i = 0; mensajes[i]; i++)
	{
		length = str_length(data->tokens[1]);
		if (str_compare(data->tokens[1], mensajes[i], length))
		{
			_print(mensajes[i] + length + 1);
			return (1);
		}
	}
	/*if there is no match, print error and return -1 */
	errno = EINVAL;
	perror(data->command_name);
	return (0);
}