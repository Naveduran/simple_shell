#include "shell.h"

int _getline(char **lineptr)
{
	ssize_t buffer_size = 256;
	char line[256] = {'\0'};
	ssize_t bytesread;
	int count_bytes = 0;

	do
	{
		bytesread = read (STDIN_FILENO, &line, buffer_size - 1);
		if (bytesread == 0 && count_bytes == 0)
		return ( - 1);
	}
	return (count_bytes);
}
