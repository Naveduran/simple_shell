#include "shell.h"
/**
 * expansions - search for $? and $$ to include the errno and the shell
 * pid respectively
 * @data: a pointer to the struct that contains the inputline
 * Return: 0 if success or 1 if error
 */

int expansions(data_of_program *data)
{
	int i = 0, number = 0;
	char expansion[10] = {0};
	char *delimiter = NULL;
	char *original = NULL;

	if (data->input_line == NULL)
		return (0);
	for (i = 0; data->input_line[i]; i++)
	{
		if (data->input_line[i] == '#')
		{
			data->input_line = '\0';
			break;
		}
		if (data->input_line[i] == '$')
		{
			if (data->input_line[i + 1] == '?' || data->input_line[i + 1] == '$')
			{
				original = str_duplicate(data->input_line);
				free(data->input_line);
				delimiter = "$";
				if (original[i + 1] == '?')
					number = errno;
				else
					number = (int) getpid();
				data->input_line = str_duplicate(_strtok(original, delimiter));
				long_to_string((long) number, expansion, 10);
				data->input_line = str_concat(data->input_line, expansion);
				data->input_line = str_concat(data->input_line, original + i + 2);
				free(original);
			}
		}
	}
	return (0);
}
