#include "shell.h"
/**
 * main - shows a prompt, receives strings from the command line, and erase
 * the last newline
 * @argc: number of values received from the command line
 * @argv: values received from the command line
 * Return: zero on succes.
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	char *string = NULL, *program, *prompt = "", **tokens = NULL;
	size_t size;
	int exec_counter = 0, errorcode = 0;

	program = argv[0];
	errno = 0;
	if ((isatty(STDIN_FILENO) && isatty(STDOUT_FILENO)))
		prompt = "dali<3 ";/* We in the terminal */
	while (++exec_counter)
	{
		_print(prompt);
		errorcode = getline(&string, &size, stdin);
		if (errorcode == EOF)
			exit(errno);/* if EOF is the fisrt Char of string, exit*/
		if (errorcode > 1)
		{
			tokens = tokenize(string, tokens, program);
			if (tokens[0])
			{/* if a text is given to prompt, execute */
				errorcode = execute(tokens, program);
				if (errorcode != 0)
					_print_error(errorcode, exec_counter, tokens, program);
			}
			if (tokens) /* test */
				free_array_of_pointers(tokens);
		}
		string = NULL;
	}
	return (0);
}
