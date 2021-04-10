#include "shell.h"

/**
 * find_program - find a program in path
 *
 * @program_name: pointer to string that represent a function name
 * Return: pointer to full path of program or NULL
 */
char *find_program(char *program_name)
{
	int i = 0;
	char *path_found = NULL;
	char **directories;
	struct stat sb;

	if (!program_name)
		return (NULL);

/* the function_name includes the full path */
	if (program_name[0] == '/' || program_name[0] == '.')
		return (str_duplicate(program_name));

/* checks for ~ expansion */
	/*if (program_name[0] == '~')*/

	/*searh for aliases*/

	program_name = str_concat(str_duplicate("/"), program_name);
	if (!program_name)
		return (NULL);
	/*search in the PATH*/
	directories = tokenize_path();
	if (!directories)
	{
		free(program_name);
		return (NULL);
	}

	for (i = 0; directories[i] && directories && program_name; i++)
	{
/* appends the function_name to path*/
		directories[i] = str_concat(directories[i], program_name);

/* stat checks if program exists and returns the full path of program*/
		if (stat(directories[i], &sb) != -1)
		{
			errno = 0;
			path_found = str_duplicate(directories[i]);
			free_array_of_pointers(directories);
			free(program_name);
			return (path_found);
		}

	}
/*if the program no was founs*/
	free(program_name);
	free_array_of_pointers(directories);
	return (NULL);
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
			tokens[j] = str_duplicate(strtok(PATH, ":"));

			while (tokens[j++])
			{
				tokens[j] = str_duplicate(strtok(NULL, ":"));
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

/**
 * free_array_of_pointers - frees each pointer of an array of pointers and the
 * array too
 * @directories: array of pointers
 * Return: nothing
 */
void free_array_of_pointers(char **directories)
{
	int i;

	if (directories != NULL)
	{
		for (i = 0; directories[i]; i++)
			free(directories[i]);

		free(directories);
		directories = NULL;
	}
}
