#include "shell.h"

/**
 * builtin_exit - exit of the program with the status
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_exit(data_of_program *data)
{
	int i;

	if (data->tokens[1] != NULL)
	{/*if exists arg for exit, check if is a number*/
		for (i = 0; data->tokens[1][i]; i++)
			if ((data->tokens[1][i] < '0' || data->tokens[1][i] > '9')
				&& data->tokens[1][i] != '+')
			{/*if is not a number*/
				errno = 2;
				return (2);
			}
		errno = _atoi(data->tokens[1]);
	}
	free_data_all(data);
	exit(errno);
}

/**
 * builtin_cd - change the current directory
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_cd(data_of_program *data)
{
	char *home_dir = env_get_key("HOME", data), *new_dir = data->tokens[1];
	char *old_dir = env_get_key("OLDPWD", data), *father_dir;
	long size = 1000;
	int i, j;
	char *work_dir = (char *)malloc((size_t)size);

	if (work_dir != NULL)
		getcwd(work_dir, (size_t)size);
	else /* failed to allocate space for work_dir*/
		perror(data->program_name), exit(errno);

	if (str_compare(new_dir, "~", 0) || str_compare(new_dir, NULL, 0))
		env_set_key("OLDPWD", work_dir, data), chdir(home_dir);
	else if (str_compare(new_dir, "..", 0)) /* This works */
	{
		env_set_key("OLDPWD", work_dir, data);
		j = str_length(work_dir);
		for (i = j; i != 0; i--)
		{
			if (work_dir[i] == '/')
			{
				work_dir[i] = '\0';
				break;
			}
		}
		father_dir = work_dir;
		chdir(father_dir);
	}
	else if (str_compare(new_dir, "/", 0)) /*This works*/
		env_set_key("OLDPWD", work_dir, data), chdir(("/"));
	else if (str_compare(new_dir, work_dir, 0)) /*This works*/
	{
	}
	else if (str_compare(new_dir, "-", 0)) /* I fail here */
		env_set_key("OLDPWD", work_dir, data), chdir(old_dir);
	else /*This doesn't work*/
		env_set_key("OLDPWD", work_dir, data), chdir(new_dir);
	free(work_dir);
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


	mensajes[0] = HELP_MSG;
	/* validate args */
	if (data->tokens[1] == NULL)
	{
		_print(mensajes[0] + 6);
		return (1);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	mensajes[1] = HELP_EXIT_MSG;
	mensajes[2] = HELP_ENV_MSG;
	mensajes[3] = HELP_SETENV_MSG;
	mensajes[4] = HELP_UNSETENV_MSG;
	mensajes[5] = HELP_CD_MSG;

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

/**
 * builtin_alias - add, remove or show aliases
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int builtin_alias(data_of_program *data)
{
	int i = 0;

	if (data->tokens[1] == NULL)
		return (print_alias(data, NULL));

	while (data->tokens[++i])
	{
		if (count_characters(data->tokens[i], "="))
		{
			set_alias(data->tokens[i], data);
		}
		else
			print_alias(data, data->tokens[i]);
	}

return (0);
}
