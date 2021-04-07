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

/* the function_name includes the full path */
	if (program_name[0] == '/')
		return (program_name);

	directories = tokenize_path();

	program_name = str_concat(str_duplicate("/"), program_name);

	for (i = 0; directories[i]; i++)
	{
/* appends to directori, the function_name */
		directories[i] = str_concat(directories[i], program_name);

/* stat returns 0 when full path exists */
		if (stat(directories[i], &sb) != -1)
		{
			/*free(sb);*/
			/* TODO: verificar errores */
			errno = 0;
			path_found = str_duplicate(directories[i]);
			free_array_of_pointers(directories);
			free(program_name);
			return (path_found);
		}

	}
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
	/*error de path no encontrado*/
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
