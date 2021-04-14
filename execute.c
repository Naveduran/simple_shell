#include "shell.h"
/**
 * execute - execute a command with its entire path variables.
 * @data: a pointer to the program's data
 * Return: If sucess returns zero, otherwise, return -1.
 */
int execute(data_of_program *data)
{
	int retval = 0, status;
	pid_t pidd;

	retval = builtins_list(data);
	if (retval != -1)
		return (retval);

	find_program(data);
	if (!data->tokens[0])
	{/* if program not found */
		errno = 127;
		return (127);
	}
	else
	{
		pidd = fork(); /* create a child process */
		if (pidd == -1) /*if error when fork*/
			perror(data->command_name), exit(EXIT_FAILURE);
		if (pidd == 0)
		{/* if I am the child, I execute*/
			retval = execve(data->tokens[0], data->tokens, data->env);
			if (retval == -1) /* if error when execve*/
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{/* If I am the father I wait */
			wait(&status); /* check the exit status of the child */
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
