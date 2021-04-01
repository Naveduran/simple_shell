#include "shell.h"

/**
 * execute - execute a command with its entire path
 * @environment: pointer to the first element of the array of environment
 * variables.
 * @tokens: contains the entire path of the command to be executed
 * Return: If sucess returns zero, otherwise, return -1.
 */
int execute(token_node **tokens, char *environment[])
{
	int value;
	char *arguments[] = {tokens[0]->token, NULL};

	if (tokens[0])
	{
		value = execve(arguments[0], arguments, environment);
		if (value == -1)
		{
			printf("./shell: No such file or directory\n");
			return (-1);
		}
		else
		{
			return (0);
		}
	}
	printf("./shell: No such file or directory\n");
	return (-1);
}
