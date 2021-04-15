#include "shell.h"

/**
 * main - initialize the variables of the program
 * @UNUSED: number of values received from the command line
 * @argv: values received from the command line
 * @env: number of values received from the command line
 * Return: zero on succes.
 */

int main(int argc UNUSED, char *argv[], char *env[])
{
	data_of_program data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";
	int is_interactive = 0;

	inicialize_data(data, argv, env);
	signal(SIGINT, handle_ctrl_c);
	if ((isatty(STDIN_FILENO) && isatty(STDOUT_FILENO)))
	{
		prompt = PROMPT_MSG;/* We are in the terminal, interactive mode */
		is_interactive = 1;
	}

	errno = 0;
	sisifo(prompt, is_interactive, data);
	return (0);
}

/**
 * handle_ctrl_c - print the prompt in a new line
 * when the signal SIGINT (ctrl + c) is send to the program
 * @UNUSED: option of the prototype
 */
void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}

/**
 * inicialize_data - inicialize the struct with the info of the program
 * @data: pointer to the structure of data
 * @argv: array of arguments pased to the program execution
 * @env: environ pased to the program execution
 */
void inicialize_data(data_of_program *data, char *argv[], char *env[])
{
	int i = 0;

	data->program_name = argv[0];
	data->exec_counter = 0;
	data->input_line = NULL;
	data->tokens = NULL;
	data->command_name = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			data->env[i] = str_duplicate(env[i]);
		}
	}
	data->env[i] = NULL;

}

/**
 * sisifo - its a infinite loop that shows the prompt
 * @prompt: prompt to be printed
 * @UNUSED: 1 if is interactive and 0 if not
 * @data: its a infinite loop that shows the prompt
 */
void sisifo(char *prompt, int is_interactive UNUSED, data_of_program *data)
{
	int error_code = 0, string_len = 0;
	size_t size;

	while (++(data->exec_counter))
	{
		_print(prompt);
		/*error_code = string_len = _getline(&data->input_line);*/
		error_code = string_len = getline(&data->input_line, &size, stdin);
		if (error_code == EOF)
		{
			free_data_all(data);
			exit(errno);/* if EOF is the fisrt Char of string, exit*/
		}
		if (string_len >= 1)
		{
			expansions(data);
			tokenize(data);
			if (data->tokens[0])
			{/* if a text is given to prompt, execute */
				error_code = execute(data);
				if (error_code != 0)
					_print_error(error_code, data);
			}
			free_data(data);
		}

	}
}
