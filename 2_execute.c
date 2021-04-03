#include "shell.h"
/**
 * execute - execute a command with its entire path
 * @environment: pointer to the first element of the array of environment
 * variables.
 * @tokens: contains the entire path of the command to be executed
 * Return: If sucess returns zero, otherwise, return -1.
 */
int execute(char *tokens[], char *environment[])
{
	int retvalB = 0, retvalC = 0, status;
	pid_t pidd;

	retvalB = builtins_structure(tokens);
	if (retvalB != 0)
		return (retvalB);
	if (tokens[0])
	{
		pidd = fork(); /* create a child process */
		if (pidd == -1)
			return (-1);
		if (pidd == 0) /* if I am the child, I execute*/
		{
			retvalC = execve(tokens[0], tokens, environment);
			if (retvalC == -1)
			{
				printf("./shell: No such file or directory\n");
				return (-1);
			}
		}
		else /*If I am the father I wait*/
			wait(&status);
	}
	return (0);
}
