#include "shell.h"

/**
 * _print - writes a array of chars in the standar output
 * @string: pointer to the array of chars
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}
/**
 * _printe - writes a array of chars in the standar error
 * @string: pointer to the array of chars
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printe(char *string)
{
	return (write(STDERR_FILENO, string, str_length(string)));
}

/**
 * _print_error - writes a array of chars in the standart error
 * @errorcode: error code.
 * @exec_counter: counter of comands procesed.
 * @tokens: pointer to the array of chars.
 * @prog: the name of the executable program
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int _print_error(int errorcode, int exec_counter, char *tokens[], char *prog)
{
	char string[4] = {'\0'};

	long_to_string((long) exec_counter, string, 10);

	if (errorcode == 2)
	{
		_printe(prog);
		_printe(": ");
		_printe(string);
		_printe(": ");
		_printe(tokens[0]);
		_printe(": Illegal number: ");
		_printe(tokens[1]);
		_printe("\n");
	}
	else if (errorcode == 127)
	{
		_printe(prog);
		_printe(": ");
		_printe(string);
		_printe(": ");
		_printe(tokens[0]);
		_printe(": not found\n");
	}
	return (0);
}
