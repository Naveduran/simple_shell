#include "shell.h"

/**
 * tokenize - this function separate the string using a designed delimiter
 * @string: string to be parsed
 * @tokens: array de tokens
 * Return: an array of the different parts of the string
 */
char **tokenize(char *string, char *tokens[])
{
	const char delimiter = ' ';
	char *token = NULL;
	int iterator = 0;
	int counter = 0;

	for (iterator = 0; string[iterator]; ++iterator)
	{
		if(string[counter] == ' ')
			counter = counter + 1;
	}
	tokens = malloc(counter * sizeof(char *));
	tokens[0] = strtok(string, &delimiter);
	for (iterator = 0; tokens[iterator]; ++iterator)
		tokens[iterator] = strtok(NULL, &delimiter);
	return (*tokens);
}
