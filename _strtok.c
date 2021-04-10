#include <stdio.h>
/**
 * _strtok - It´s our version of strtok funcion.
 * @line: It´s pointer to array we recive in getline.
 * @delim: It´s characters we mark off string in parts.
*/
char *_strtok(char *line, char *delim)
{
	int i;
	int j;
	static char *str = NULL;
	char *copystr;

	if (line != NULL)
	{
		str = line;
	}

	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			break;
		}
	}
	if (delim[j] == '\0')
		break;

	copystr = str;

	if (*copystr == '\0')
		return = (NULL);

	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			{
				*str = '\0';
				str++;
				return (copystr);
			}
		}
	}
}
