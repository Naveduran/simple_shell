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
}
