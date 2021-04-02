#include "shell.h"
/**
 * main - shows a prompt and receives strings from the command line
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
	token_node *tokens = NULL, *string2 = NULL;
	int string_length = 0;

	while (1)
	{
		printf("dali<3 ");
		getline(&string, &size, stdin);
/*replace newline at the end of getline for a null character:*/
		string_length = str_length(string);
		string[string_length - 1] = '\0';
/*if there are arguments given to dali<3 execute them*/
		if (string_length > 1)
		{
			 = tokenize(string, &tokens);
			if (string2 == NULL)
				exit(98);
			execute(&tokens, env);
			free_tokens_list(tokens);
		}
	}
	return (0);
}
