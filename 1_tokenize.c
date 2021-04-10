#include "shell.h"


/**
 * tokenize - this function separate the string using a designed delimiter
 * @string: string to be parsed
 * @tokens: array de tokens
 * @who_i_am: name of the executed file
 * Return: an array of the different parts of the string
 */
char **tokenize(char *string, char **tokens, char *who_i_am)
{
	const char *delimiter = " \n\t";
	int iterator = 0;
	int counter = 2;

	for (iterator = 0; string[iterator]; iterator++)
	{
		if (string[iterator] == ' ')
			counter++;
	}

	tokens = malloc(counter * sizeof(char *));
	if (tokens == NULL)
	{
		perror(who_i_am);
		exit(errno);
	}

	counter = 0;
	tokens[counter] = strtok(string, delimiter);

	while (tokens[counter++])
	{
		tokens[counter] = strtok(NULL, delimiter);
	}

	return (tokens);
}
