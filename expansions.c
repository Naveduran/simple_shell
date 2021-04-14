#include "shell.h"

/**
 * expansions - search for $? and $$ to include the errno and the shell
 * pid respectively
 * @data: a pointer to the struct that contains the inputline
 * Return: 0 if success or 1 if error
 */

int expansions(data_of_program *data)
{	int i = 0, number = 0;
	char expansion[10] = {0}, *expansion2, *delimiter = NULL, *original = NULL;

	if (data->input_line == NULL)
		return (0);
	for (i = 0; data->input_line[i]; i++)
	{
		if (data->input_line[i] == '#')
		{
			data->input_line = '\0';
			return (0);
		}
		if (data->input_line[i] == '$')
			if (data->input_line[i + 1] == '?' || data->input_line[i + 1] == '$')
			{
				delimiter = "$";
				if (original[i + 1] == '?')
					number = errno;
				else
					number = (int) getpid();
				long_to_string((long) number, expansion, 10);
				original = str_duplicate(data->input_line);
				free(data->input_line);
				data->input_line = str_duplicate(_strtok(original, delimiter));
				data->input_line = str_concat(data->input_line, expansion);
				data->input_line = str_concat(data->input_line, original + i + 2);
				free(original);
			}
		if (data->input_line[i] == '~')
		{
			delimiter = "~";
			expansion2 = env_get_key("HOME", data);
			original = str_duplicate(data->input_line), free(data->input_line);
			data->input_line = str_duplicate(_strtok(original, delimiter));
			data->input_line = str_concat(data->input_line, expansion2);
			data->input_line = str_concat(data->input_line, original + i + 2);
			printf("newline = %s\n", data->input_line);
			free(original);
		}
	}
	return (0);
}
