#include "shell.h"

/**
 * tokenize - this function separate the string using a designed delimiter
 * @string: string to be parsed
 * @tokens: array de tokens
 * Return: an array of the different parts of the string
 */
token_node *tokenize(char *string, token_node **tokens)
{
	const char delimiter = ' ';
	char *token = NULL;

	do {
		if (token == NULL)
			token = strtok(string, &delimiter);
		else
			token = strtok(NULL, &delimiter);

		if (token)
			add_token(tokens, token);

	} while (token);

	return (*tokens);
}
