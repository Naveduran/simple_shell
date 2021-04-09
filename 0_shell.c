#include "shell.h"

char *who_i_am;

/**
 * main - shows a prompt, receives strings from the command line, and erase
 * the last newline
 * @argc: number of values received from the command line
 * @argv: values received from the command line
 *
 * Return: zero on succes.
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	char *string = NULL, *prompt = "dali<3 ";
	char **tokens = NULL;
	size_t size;
	int exec_counter = 0, result = 0;

	who_i_am = argv[0];

/*checks for interactive mode*/
	if (!(isatty(STDIN_FILENO) && isatty(STDOUT_FILENO)))
	{
		prompt = "";
	}
	errno = 0;

	while (++exec_counter)
	{
		/*show the prompt and wait for the input of the user*/
		_print(prompt);
		result = getline(&string, &size, stdin);

		/* if EOF is the fisrt Char of string, exit*/
		if (result == EOF)
			exit(errno);

		/*if there are text given to dali<3, execute them*/
		if (result > 1)
		{
			tokens = tokenize(string, tokens);
			if (tokens[0])
			{
				if (str_compare("exit", tokens[0], 0))
					result = builtin_exit(tokens, string);
				else
					result = execute(tokens);

				if (result != 0)
					_print_error(result, exec_counter, tokens[0], tokens[1]);
			}

			if (tokens)
				free(tokens);
			tokens = NULL;

		}
		if (string)
			free(string);
		string = NULL;
	}
}
