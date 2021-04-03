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
	int returvalueB = 666, returvalueC = 666, status;
	char *arguments[] = {tokens[0]->token, NULL};
	pid_t pidd;

/* try to execute the builtin if its a builtin */
	returvalueB = builtins_structure(tokens);
/*if execute the builtin, return the returnvalue of the builtin*/
	if (returvalueB != 0)
		return (returnvalueB);
/* try to execute the command, if its a command */
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
			returvalueC = execve(arguments[0], arguments, environment);
			printf("function executed, execve returns:%d\n", returvalueC);
/* If it can not execute the command, print an error message*/
			if (returvalueC == -1)
			{
				printf("./shell: No such file or directory\n");
				return (-1);
			}
/* If it execute the command, return the value of return of the command*/
		}
		else /*If I am the father I wait*/
			wait(&status);
		if (WIFEXITED(&status) != 1) /*If child ended anormally*/
		{
			printf("The command was found and executed,
but ended anormally. WEXITSTATUS:%d\n", WEXITSTATUS(status));
		}
	}
	return (0);
}
