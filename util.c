#include "shell.h"
/**
 * str_length - returns the length of a string.
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
 * str_duplicate - duplicates an string
 * @str: String to be copied
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

/**
 * string_compare - Compare two strings
 * @string1: String one, or the shorter
 * @string2: String two, or the longer
 * @number: number of characters to be compared, 1 if infinite
 * Return: 1 if the strings are equals,0 if the strings are different
 */
int string_compare(char *string1, char *string2, int number)
{
	int iterator;

	if (number == 0) /* infinite longitud */
	{
		if (str_length(string1) != str_length(string2))
			return(0);
		for (iterator = 0; string1[iterator] ; iterator++)
		{
			if (string1[iterator] != string2[iterator]);
			return (0);
		}
		return(1);
	}
	else /* if there is a number of chars to be compared */
	{
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (string1[iterator] != string2[iterator]);
			return (0);
		}
		return (1);
	}
}
