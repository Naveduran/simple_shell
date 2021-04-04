#include "shell.h"

/**
 * find_program - find a program in path
 *
 * @function_name: pointer to string that represent a function name
 * Return: pointer to full path of program or NULL
 */
char *find_program(char *function_name)
{
	int i = 0, j = 0;
	char *sub_path = NULL;
	char *directories;
	int counter_adress = 1;
	struct stat *sb;

/* the function_name includes the full path */
	if (function_name[0] == '/')
		return (function_name);


}
