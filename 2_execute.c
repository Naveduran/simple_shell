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
	int retvalB = 666, retvalC = 666, status;
	char *arguments[] = {tokens[0]->token, NULL};
	pid_t pidd;

	retvalB = builtins_structure(tokens);
	if (retvalB != 0)
		return (retvalB);
	if ((*tokens)->token)
	{
		pidd = fork(); /* create a child process */
		printf("I have create a child with the pid = %d\n", pidd);
		if (pidd == -1)
		{
			printf("Error haciendo el fork para ejecutar\n");
			return (-1);
		}
		if (pidd == 0) /* if I am the child, I execute*/
		{
			retvalC = execve(arguments[0], arguments, environment);
			printf("functionexecuted,execve returns:%d\n", retvalC);
			if (retvalC == -1)
			{
				printf("./shell: No such file or directory\n");
				return (-1);
			}
		}
		else /*If I am the father I wait*/
			wait(&status);
		if (WIFEXITED(&status) != 1) /*If child ended anormally*/
		{
			printf("The command was found and executed, but ended");
			printf(" anormally. ");
			printf("WEXITSTATUS:%d\n", WEXITSTATUS(status));
		}
	}
	return (0);
}
