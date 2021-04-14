#include "shell.h"

/**
* _getline - read one line from the prompt.
* @buffer_size: size of buffer reserve for text.
* @line: text array.
* @bytesread: size of bytes return read.
* @count_bytes: total bytes.
*/

int _getline(char **lineptr)
{
	ssize_t buffer_size = 256;
	char line[256] = {'\0'};
	ssize_t bytesread;
	int count_bytes = 0;

	do {
		bytesread = read(STDIN_FILENO, &line, buffer_size - 1);
		if (bytesread == 0 && count_bytes == 0)
			return (-1);

		count_bytes += bytesread;
		line[bytesread] = '\0';

		if (*lineptr == NULL)
			*lineptr = str_duplicate(line);
		else
			*lineptr = str_concat(*lineptr, line);
	} while (bytesread == (buffer_size - 1) && line[bytesread - 1] != '\n');
	return (count_bytes);
}
