#include "shell.h"
/**
 * execute - execute a command with its entire path
 * @environment: pointer to the first element of the array of environment
 * variables.
 * @tokens: contains the entire path of the command to be executed
 * Return: If sucess returns zero, otherwise, return -1.
 */
int execute(char *tokens[])
{
	int retval = 0, status;
	pid_t pidd;

	retval = builtins_structure(tokens);
	if (retval != 0)
		return (retval);

	tokens[0] = find_program(tokens[0]);

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
			wait(&status);
	}
	/* manejar el error*/
	return (0);
}
