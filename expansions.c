#include "shell.h"

/**
 * expansions - reeplace the symbols $?, $$ and ~ for the errno,
 * the process id, or the home directory respectively.
 * @data: a pointer to the struct that contains the inputline
 * Return: 0 if success or 1 if error
 */

int expansions(data_of_program *data)
{	int i = 0, j = 0, k = 0, number = 0, l = 0, boolean = 0;
	char ex[10] = {0}, *exp = NULL, *del = NULL;
	char *ori = NULL, var[20] = {0}, *vari = var + 1;

	if (data->input_line == NULL)
		return (0);
	for (i = 0; data->input_line[i]; i++)
	{
		if (data->input_line[i] == '#')
		{ data->input_line[i] = '\0';
			return (0); }
		if (data->input_line[i] == '$')
			if (data->input_line[i + 1] == '?' || data->input_line[i + 1] == '$')
			{	del = "$", exp = ex, l = 2;
				if (data->input_line[i + 1] == '?')
					number = errno;
				else
					number = (int) getpid();
				long_to_string((long) number, ex, 10), concat_exp(data, del, exp, i, l);
			}
			else
			{	j = i, k = 0;
				while (data->input_line[j] != ' ' && data->input_line[j] != '\n')
					var[k] = data->input_line[j], j++, k++;
				if (env_get_key(vari, data) != NULL)
				{ del = "$", l = k, exp = env_get_key(vari, data);
					concat_exp(data, del, exp, i, l); }
			}
		if (data->input_line[i] == '~')
		{	del = "~", exp = env_get_key("HOME", data), l = 1;
			if (i == 0)
			{	ori = str_duplicate(data->input_line), free(data->input_line);
				data->input_line = exp;
				data->input_line = str_concat(str_duplicate(data->input_line), ori + 1);
				free(ori);
			}
			else
				concat_exp(data, del, exp, i, l);
		}
	}
	return (0);
}

/**
 * concat_exp - concatenates strings to expand the input line
 * @data: a pointer to a struct of the program's data
 * @delim: the delimiter used to separate the string
 * @exp: the expasion that needs to be included
 * @i: the posision where original the delimiter was found
 * @l: the lenght of the characters to be expanded
 * Return: nothing, but sets errno.
 */

void concat_exp(data_of_program *data, char *delim, char *exp, int i, int l)
{
	char *original = NULL;

/* TO DO:comprobar que las funciones funcionan y si no generar error */

	original = str_duplicate(data->input_line);
	free(data->input_line);
	data->input_line = str_duplicate(_strtok(original, delim));
	data->input_line = str_concat(data->input_line, exp);
	data->input_line = str_concat(data->input_line, original + i + l);
	free(original);
}
