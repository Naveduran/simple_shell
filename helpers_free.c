#include "shell.h"
/**
 * long_to_string - converts a number to a string.
 * @number: number to be converten in an string.
 * @string: buffer to save the number as string.
 * @base: base to convert number
 *
 * Return: Nothing.
 */
void long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}


/**
 * handle_ctrl_c - print the prompt in a new line
 * when the signal SIGINT (ctrl + c) is send to the program
 * Return: nothing.
 */
void handle_ctrl_c(int opr __attribute__((unused)))
{
	_print("\n");
	_print(PROMPT_MSG);
}

/**
 * handle_ctrl_c - print the prompt in a new line
 * when the signal SIGINT (ctrl + c) is send to the program
 * Return: nothing.
 */
void free_data(data_of_program *data)
{
	if (data->tokens)
		free_array_of_pointers(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name=NULL;
	data->tokens= NULL;
}

/**
 * handle_ctrl_c - print the prompt in a new line
 * when the signal SIGINT (ctrl + c) is send to the program
 * Return: nothing.
 */
void free_data_all(data_of_program *data)
{
	free_data(data);
	free_array_of_pointers(data->env);
}


/**
 * free_array_of_pointers - frees each pointer of an array of pointers and the
 * array too
 * @directories: array of pointers
 * Return: nothing
 */
void free_array_of_pointers(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}