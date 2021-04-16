#include "shell.h"

/**
* _getline - read one line from the prompt.
* @lineptr: pointer to a pointer of char strings.
*
* Return: reading counting bytes.
*/

int _getline(char **lineptr)
{
	char buffer[BUFFER_SIZE_GETLINE] = {'\0'};
	static char *array_lines[10] = {NULL};
	ssize_t bytes_read, i;

	if (!array_lines[0])
	{
		bytes_read = read(STDIN_FILENO, &buffer, BUFFER_SIZE_GETLINE - 1);
		if (bytes_read == 0)
			return (-1);

		i = 0;

		array_lines[i] = str_duplicate(_strtok(buffer, "\n;"));
		while (array_lines[i++])
			array_lines[i] = str_duplicate(_strtok(NULL, "\n;"));

		array_lines[i] = NULL;
	}

	i = 0;
	*lineptr = array_lines[i];

	while (array_lines[i++])
		array_lines[i - 1] = array_lines[i];

	return (str_length(*lineptr));
}
