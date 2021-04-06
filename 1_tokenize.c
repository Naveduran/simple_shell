#include "shell.h"

/**
 * tokenize - this function separate the string using a designed delimiter
 * @string: string to be parsed
 * @tokens: array de tokens
 * Return: an array of the different parts of the string
 */
char **tokenize(char *string, char **tokens)
{
	const char *delimiter = " \n\t";
	char *token = NULL, *string2 = string;
	int iterator = 0;
	int counter = 1;

	for (iterator = 0; string[iterator]; iterator++)
	{
		if(string[iterator] == ' ')
			counter++;
	}

	tokens = malloc(counter * sizeof(char *));
	if (tokens == NULL)
	{
		printf("el malloc no funcionó\n");
		return(NULL);
	}

	counter = 0;
	tokens[counter] = strtok(string, delimiter);
	while (tokens[counter])
	{
		counter++;
		tokens[counter] = strtok(NULL, delimiter);
	}

	return (tokens);
}
