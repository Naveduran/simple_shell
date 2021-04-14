#include "shell.h"

/**
 * expansions - search for $? and $$ to include the errno and the shell
 * pid respectively
 * @input_line: a pointer to the original string
 * Return: 0 if success or 1 if error
 */

int expansions(data_of_program *data)
{
    int i = 0, number = 0;
	int buffer[5];
	int previouslength = 0;
	ssize_t bytes_read;
	pid_t pidd;
	char expansion[10]= {0};
	char *delimiter= NULL;
	char *original = NULL, *v = NULL, *v2 = NULL;

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
				if (original[i + 1] == '$')
					number = pidd;

				data->input_line = str_duplicate(_strtok(original, delimiter));
				long_to_string((long) number, expansion, 10);
				data->input_line = str_concat(data->input_line, expansion);
				data->input_line = str_concat(data->input_line, _strtok(NULL, delimiter) + 1);
			}
		}
	}
		return (0);
}
