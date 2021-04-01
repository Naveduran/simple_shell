#include "shell.h"

/**
 * main - shows a prompt and receives strings from the command line
 * @argc: number of values received from the command line
 * @argv: values received from the command line
 * @env: environment.
 *
 * Return: zero always.
 */

int main(int argc, char *argv[], char *env[])
{
	char *string, *string2;
	size_t size;
	int iterator;
	while (1)
	{
		printf("dali<3 ");
		getline(&string, &size, stdin);
		/*Quitar enter que deja getline:  */
		for (iterator = 0; string[iterator]; iterator++)
		{

		}
		string[iterator - 1] = '\0';
		/*TODO: partir en pedazos la string para tomar los argumentos */
		/*              string2 = tokenize(string);*/
		execute(string, env);
	}
	return (0);
}
