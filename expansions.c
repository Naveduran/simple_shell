#include "shell.h"

int buffer_add(char *buffer, char *str_to_add);



/**
 * expand_variables - expand variables
 * @data: a pointer to a struct of the program's data
 *
 * Return: nothing, but sets errno.
 */
int expand_variables(data_of_program *data)
{
	int i, j, was_expanded = 0;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return (0);

	buffer_add(line, data->input_line);

	for (i = 0; line[i]; i++)
	{
		if (line[i] == '#')
		{
			line[i] = '\0';
			i--;
			was_expanded = 1;
		}
		else if (line[i] == '$')
		{
			if (line[i + 1] == '?')
			{
				line[i] = '\0';
				long_to_string(errno, expansion, 10);
				buffer_add(line, expansion);
				buffer_add(line, data->input_line + i + 2);
			}
			else if (line[i + 1] == '$')
			{
				line[i] = '\0';
				long_to_string(getpid(), expansion, 10);
				buffer_add(line, expansion);
				buffer_add(line, data->input_line + i + 2);
			}
			else
			{
				for (j = 1; line[i + j] && line[i + j] != ' '; j++)
					expansion[j - 1] = line[i + j];

				temp = env_get_key(expansion, data);
				if (temp)
				{
					line[i] = '\0';
					expansion[0] = '\0';
					buffer_add(expansion, line + i + j);
					buffer_add(line, temp);
					buffer_add(line, expansion);
				}
			}
			was_expanded = 1;
		}
	}
	if (was_expanded)
	{
		free(data->input_line);
		data->input_line = str_duplicate(line);
	}
	return (0);
}

/**
 * expand_alias - expans aliases
 * @data: a pointer to a struct of the program's data
 *
 * Return: nothing, but sets errno.
 */
int expand_alias(data_of_program *data)
{
	int i, j, was_expanded = 0;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return (0);

	buffer_add(line, data->input_line);

	for (i = 0; line[i]; i++)
	{
		for (j = 0; line[i + j] && line[i + j] != ' '; j++)
			expansion[j] = line[i + j];
		expansion[j] = '\0';

		temp = get_alias(data, expansion);
		if (temp)
		{
			expansion[0] = '\0';
			buffer_add(expansion, line + i + j);
			line[i] = '\0';
			buffer_add(line, temp + 1);
			line[str_length(line) - 1] = '\0';
			buffer_add(line, expansion);
			was_expanded = 1;
		}
		break;
	}
	if (was_expanded)
	{
		free(data->input_line);
		data->input_line = str_duplicate(line);
	}
	return (0);
}

/**
 * buffer_add - append string at end of the buffer
 * @buffer: buffer to be filled
 * @str_to_add: string to be copied in the buffer
 * Return: nothing, but sets errno.
 */
int buffer_add(char *buffer, char *str_to_add)
{
	int length, i;

	length = str_length(buffer);
	for (i = 0; str_to_add[i]; i++)
	{
		buffer[length + i] = str_to_add[i];
	}
	buffer[length + i] = '\0';
	return (length + i);
}
