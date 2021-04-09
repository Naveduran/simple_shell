#include "shell.h"

extern char *who_i_am;

/**
 * _print - writes a array of chars in the standart output
 * @string: pointer to the array of chars
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}

int _print_error(int code, int exec_counter, char *func_name, char *arg)
{
	if (code == 2)
	{
		fprintf(stderr, "%s: %i: %s: Illegal number: %s\n",
			who_i_am, exec_counter, func_name, arg);
	}
	else if (code == 127)
	{
		fprintf(stderr, "%s: %i: %s: not found\n", who_i_am,
			exec_counter, func_name);
	}
	return (0);
}
