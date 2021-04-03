#include "shell.h"
/**
 * str_length - returns the length of a string.
 *
 * @string: pointer to string.
 * Return: length of string.
 */
int str_length(char *string)
{
	int length = 0;

	while (string[length++] != '\0')
	{
	}

	return (--length);
}


/**
 * str_duplicate - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 * @str: String to be copied
 *
 * Return: pointer to the array
 */
char *str_duplicate(char *string)
{
	char *resultado;
	int string_len, i;

	if (string == NULL)
		return (NULL);

	string_len = str_length(string);

	resultado = malloc(sizeof(char) * (string_len + 1));
	if (resultado == NULL)
		return (NULL);

	for (i = 0; i < string_len ; i++)
	{
		resultado[i] = string[i];
	}

	resultado[string_len] = '\0';

	return (resultado);
}
