#include "shell.h"

void inicialize_data(data_of_program *data, char *argv[], char *env[]);

/**
 * main - shows a prompt, receives strings from the command line, and erase
 * the last newline
 * @argc: number of values received from the command line
 * @argv: values received from the command line
 * Return: zero on succes.
 */
int main(int argc UNUSED, char *argv[], char *env[])
{
	data_of_program data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";
	size_t size;
	int error_code = 0, is_interactive = 0;

	inicialize_data(data, argv, env);
	signal(SIGINT, handle_ctrl_c);
	errno = 0;
	if ((isatty(STDIN_FILENO) && isatty(STDOUT_FILENO)))
	{
		prompt = PROMPT_MSG;/* We in the terminal */
		is_interactive = 1;
	}
	while (++(data->exec_counter))
	{
		_print(prompt);
		error_code = getline(&data->input_line, &size, stdin);
		if (error_code == EOF)
			exit(errno);/* if EOF is the fisrt Char of string, exit*/
		if (error_code > 1)
		{
			tokenize(data);
			if (data->tokens[0])
			{/* if a text is given to prompt, execute */
				error_code = execute(data);
				if (error_code != 0)
					_print_error(error_code, data);
			}
			free_data(data);
		}
		if (!is_interactive)
			free_data_all(data);
	}
	return (0);
}

void inicialize_data(data_of_program *data, char *argv[], char *env[])
{
	int i;

	data->program_name = argv[0];
	data->exec_counter = 0;
	data->input_line = NULL;
	data->tokens=NULL;
	data->command_name = NULL;

	/* copy to memory the environ */
	data->env = malloc(sizeof(char *) * 40);
	for (i = 0; env[i]; i++)
	{
		data->env[i] = str_duplicate(env[i]);
	}
	data->env[i] = NULL;
}
