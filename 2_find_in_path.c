#include "shell.h"

/**
 * find_program - find a program in path
 *
 * @function_name: pointer to string that represent a function name
 * Return: pointer to full path of program or NULL
 */
char *find_program(char *function_name)
{
	int i = 0, j = 0;
	char *path_found = NULL;
	char **directories;
	int counter_adress = 1;
	struct stat sb;

/* the function_name includes the full path */
	if (function_name[0] == '/')
		return (function_name);

	directories = get_path();

	for (i = 0; directories[i]; i++)
	{
/* appends to directori, the function_name */
		directories[i] = str_concat(directories[i], "/");
		directories[i] = str_concat(directories[i], function_name);

/* stat returns 0 when full path exists */
		if (stat(directories[i], &sb) != -1)
		{
			/*free(sb);*/
			/* TODO: verificar errores */
			path_found = str_duplicate(directories[i]);
			free_array_of_pointers(directories);
			return (path_found);
		}

	}
	free_array_of_pointers(directories);
	return (NULL);
}

/**
 * get_path - tokenize the path in directories
 *
 * Return: array of path directories
 */
char **get_path()
{
	int i = 0, j = 0;
	int counter_directories = 1;
	char **tokens = NULL;
	char *PATH;

	while (environ[i])
	{
		if (string_compare("PATH=", environ[i], 5))
		{

			/* find the number of directories in the PATH */
			for (j = 0; environ[i][j]; j++)
			{
				if(environ[i][j] == ':')
					counter_directories++;
			}

			PATH = str_duplicate(environ[i] + 5);
			tokens = malloc(sizeof(char *) * (counter_directories + 1));

			j = 0;
			tokens[j] = str_duplicate(strtok(PATH , ":"));

			while (tokens[j++])
			{
				tokens[j] = str_duplicate(strtok(NULL, ":"));
			}
			free (PATH);
			return (tokens);
		}
		i++;
	}

}

void free_array_of_pointers(char **directories)
{
	int i;

	if (directories != NULL)
	{
		for (i = 0; directories[i]; i++)
			free (directories[i]);

		free (directories);
		directories = NULL;
	}
}
