#include "shell.h"

/**
* _getline - read one line from the prompt.
* @lineptr: pointer to a pointer of char strings.
*
* Return: reading counting bytes.
*/

int _getline(char **lineptr)
{
	char line[BUFFER_SIZE_GETLINE] = {'\0'}, *temp = NULL;
	static char *other_line = "";
	ssize_t bytesread;
	int count_bytes = 0, i, contador = 0;

	if (other_line == NULL  || *other_line == '\0')
	{
		bytesread = read(STDIN_FILENO, &line, BUFFER_SIZE_GETLINE - 1);
		if (bytesread == 0 && count_bytes == 0)
			return (-1);
		other_line = str_duplicate(line);
		contador = 1;
	}

	/*busca saltos de linea*/
	for (i = 0; other_line[i]; i++)
	{
		if (other_line[i] == '\n')
		{
			other_line[i] = '\0';
			*lineptr = str_duplicate(other_line);
			temp = other_line;
			if (other_line[i + 1] == '\0')
				other_line = NULL;
			else
				other_line = str_duplicate(other_line + i + 1);
			free(temp);
			return (str_length(*lineptr));
		}
	}
	free(other_line);
	other_line = NULL;
	if (contador == 0)
		return (-1);
	else
		return (0);
}
