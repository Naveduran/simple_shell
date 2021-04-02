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
	int returnvalueofthebuiltin;

/*if the argument first argument is a built in, execute it*/
	returnvalueofthebuiltin = builtins_structure(tokens);

/*if it is not a built in, try to execute the command*/
	if ((*tokens)->token)
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
	else
	{
		printf("./shell: No such file or directory\n");
		return (-1);
	}
}
