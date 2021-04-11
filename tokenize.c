#include "shell.h"
/**
 * tokenize - this function separate the string using a designed delimiter
 * @string: string to be parsed
 * @tokens: array de tokens
 * @program: name of the executed file
 * Return: an array of the different parts of the string
 */
char **tokenize(char *string, char **tokens, char *program)
{
	char *delimiter = " \n\t";
	int i, j, counter = 2;

	for (i = 0; string[i]; i++)
	{
		for (j = 0; delimiter[j]; j++)
		{
			if (string[i] == delimiter[j])
				counter++;
		}
	}
	tokens = malloc(counter * sizeof(char *));
	if (tokens == NULL)
	{
		perror(program);
		exit(errno);
	}
	i = 0;
	tokens[i] = str_duplicate(_strtok(string, delimiter));
	while (tokens[i++])
	{
		tokens[i] = str_duplicate(_strtok(NULL, delimiter));
	}
	free(string);
	return (tokens);
}
