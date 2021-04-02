#include "shell.h"
/**
 * main - shows a prompt, receives strings from the command line, and erase
 * the last newline
 * @argc: number of values received from the command line
 * @argv: values received from the command line
 * @env: environment.
 *
 * Return: zero always.
 */

int main(int argc __attribute__((unused)),
char *argv[] __attribute__((unused)), char *env[])
{
	char *string = NULL;
	size_t size;
	token_node *tokens = NULL;
	int string_length = 0;

	while (1)
	{
/*show the prompt and wait for the input of the user*/
		printf("dali<3 ");
		string_length = getline(&string, &size, stdin);

/* ¡¡Hay que liberar lo que haga getline por que hace malloc!! */
/*replace newline at the end of getline for a null character:*/
		if (string[string_length - 1] == '\n')
			string[string_length - 1] = '\0';
/*if there are arguments given to dali<3 execute them*/
		if (string_length > 1)
		{
/*if EOF, exit
			if (*string == EOF)
			return (0);*/
				tokenize(string, &tokens);
/*			if (tokens == NULL)
			exit(98); */
			execute(&tokens, env);
			free_tokens_list(tokens);
		}
		free(string);
	}
	return (0);
}
