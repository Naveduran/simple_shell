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
	int returnvalueB, returnvalueC;
	char *arguments[] = {tokens[0]->token, NULL};

/* try to execute the builtin if its a builtin */
	returnvalueB = builtins_structure(tokens);

/* try to execute the command, if its a command */
	if ((*tokens)->token)
	{
		returnvalueC = execve(arguments[0], arguments, environment);
/* If it can not execute the command, print an error message*/
		if (returnvalueC == -1)
		{
			printf("./shell: No such file or directory\n");
			return (-1);
		}
/* If it execute the command, return the value of return of the command*/
		else
			return (returnvalueC);
	}
	else
	{
		printf("./shell: No such file or directory\n");
		return (-1);
	}
}
