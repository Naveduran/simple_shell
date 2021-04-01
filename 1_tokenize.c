#include "shell.h"

/**
 * tokenize - this function separate the string using a designed delimiter
 * @string: string to be parsed
 * Return: an array of the different parts of the string
 */
token_node *tokenize(char *string, token_node **tokens)
{
	const char delimiter = ' ';
	char *token = NULL;
	int string_length = 0;

	/*DONE: quitar enter que deja getline:*/
	string_length = str_length(string);
	if (string[string_length - 1] == '\n')
		string[string_length - 1] = '\0';

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
