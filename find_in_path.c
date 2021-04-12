#include "shell.h"

/**
 * find_program - find a program in path
 *
 * @program_name: pointer to string that represent a function name
 * Return: pointer to full path of program or NULL
 */
void find_program(data_of_program *data)
{
	int i = 0;
	char **directories;
	struct stat sb;

	if (!data->command_name)
		return;

/* the function_name includes the full path */
	if (data->command_name[0] == '/' || data->command_name[0] == '.')
		return;
/* checks for ~ expansion, if (program_name[0] == '~'), searh for aliases*/
	free(data->tokens[0]);
	data->tokens[0] = str_concat(str_duplicate("/"), data->command_name);
	if (!data->tokens[0])
		return;
	directories = tokenize_path();/* search in the PATH */
	if (!directories)
		return;
	for (i = 0; directories[i] && directories && data->command_name; i++)
	{/* appends the function_name to path */
		directories[i] = str_concat(directories[i], data->tokens[0]);
/* stat checks if program exists and returns the full path of program*/
		if (stat(directories[i], &sb) != -1)
		{
			errno = 0;
			free (data->tokens[0]);
			data->tokens[0] = str_duplicate(directories[i]);
			free_array_of_pointers(directories);
			return;
		}
	}
	free (data->tokens[0]);
	if (stat(data->command_name, &sb) != -1)
	{
		errno = 0;
		data->tokens[0] = data->command_name;
		free_array_of_pointers(directories);
		return;
	}
	data->tokens[0] = NULL;
	free_array_of_pointers(directories);
	return;
}

/**
 * tokenize_path - tokenize the path in directories
 *
 * Return: array of path directories
 */
char **tokenize_path()
{
	int i = 0, j = 0;
	int counter_directories = 1;
	char **tokens = NULL;
	char *PATH;

	while (environ[i])
	{
		if (str_compare("PATH=", environ[i], 5))
		{

			/* find the number of directories in the PATH */
			for (j = 0; environ[i][j]; j++)
			{
				if (environ[i][j] == ':')
					counter_directories++;
			}

			PATH = str_duplicate(environ[i] + 5);
			tokens = malloc(sizeof(char *) * (counter_directories + 1));

			j = 0;
			tokens[j] = str_duplicate(_strtok(PATH, ":"));

			while (tokens[j++])
			{
				tokens[j] = str_duplicate(_strtok(NULL, ":"));
			}
			free(PATH);
			PATH = NULL;
			return (tokens);
		}
		i++;
	}
	/*path not found*/
	return (NULL);
}


