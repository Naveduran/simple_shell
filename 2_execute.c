#include "shell.h"
/**
 * execute - execute a command with its entire path
 * variables.
 * @tokens: contains the entire path of the command to be executed
 * Return: If sucess returns zero, otherwise, return -1.
 */
int execute(char *tokens[])
{
	int retval = 0, status;
	char *command_name = tokens[0];
	pid_t pidd;

	retval = builtins_structure(tokens);
	if (retval != 0)
		return (retval);

	tokens[0] = find_program(command_name);

	if (tokens[0])
	{
		pidd = fork(); /* create a child process */

		if (pidd == -1)
			return (-1);

		if (pidd == 0) /* if I am the child, I execute*/
		{
			retval = execve(tokens[0], tokens, environ);
			if (retval == -1)
			{
				printf("./shell: No such file or directory\n");
				return (-1);
			}
		}
		else /*If I am the father I wait*/
		{
			wait(&status);
			free(tokens[0]);
			/*validar el estado de salida del hijo*/
		}
	}
	else{

		/* manejar el error*/
		printf("errno: %d\n", errno);
		perror(command_name);
	}
	return (0);
}
