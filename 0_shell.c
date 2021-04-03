#include "shell.h"
/**
 * main - shows a prompt, receives strings from the command line, and erase
 * the last newline
 * @argc: number of values received from the command line
 * @argv: values received from the command line
 * @env: environment.
 *
 * Return: zero on succes.
 */
int main(int argc, char *argv[], char *env[])
{
	char *string = NULL, *tokens = NULL;
	size_t size;
	int string_length = 0, i;
/*si se han pasado parametros al programa (modo no interactivo)*/
	if (argc > 1)
	{
		tokens = malloc(argc * sizeof(char *));
		for (i = 1; i < argc; i++)
			tokens[i - 1] = argv[i];

		execute(&tokens, env);
		free(tokens);
		return (EXIT_SUCCESS);
	}
/*si esta en modo interactivo*/
	while (1)
	{
/*show the prompt and wait for the input of the user*/
		printf("dali<3 ");
		string_length = getline(&string, &size, stdin);

		/* debe salir de manera controlada ???*/
		if (string_length == EOF)
			return (0);
/*if there are text given to dali<3, execute them*/
		if (string_length > 1)
		{
/*replace newline at the end of getline for a null character:*/
			if (string[string_length - 1] == '\n')
				string[string_length - 1] = '\0';

			tokenize(string, &tokens);
			execute(&tokens, env);
			if (tokens)
			{
				free(tokens);
				tokens = NULL;
			}
		}
	}
}
