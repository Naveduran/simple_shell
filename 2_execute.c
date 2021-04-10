#include "shell.h"

/**
 * execute - execute a command with its entire path variables.
 * @tokens: contains the entire path of the command to be executed
 * @who_i_am: name of the executed file
 * Return: If sucess returns zero, otherwise, return -1.
 */
int execute(char *tokens[], char *who_i_am)
{
	int retval = 0, status;
	char *command_name = tokens[0], *full_path;
	pid_t pidd;

	retval = builtins_structure(tokens);
	if (retval != -1)
		return (retval);

	full_path = find_program(command_name);

	if (!full_path)
	{/* if doesnot found the program */
		errno = 127;
		return (127);
	}
	else
	{
		pidd = fork(); /* create a child process */

		if (pidd == -1)
		{/*error at excecute fork*/
			perror(who_i_am);
			exit(EXIT_FAILURE);
		}

		if (pidd == 0)
		{/* if I am the child, I execute*/
			tokens[0] = full_path;
			retval = execve(tokens[0], tokens, environ);
			if (retval == -1)
			{/*error at excecute execve*/
				perror(who_i_am);
				exit(EXIT_FAILURE);
			}
		}
		else
		{/*If I am the father I wait*/
			wait(&status);
			/*validar el estado de salida del hijo*/
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
