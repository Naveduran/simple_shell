#include "shell.h"

/**
 * add_to_history - añadir token al history
 * @data: an structure with the program's data
 * Return: ..
 */
int add_to_history(data_of_program *data)
{
	llamar dentro o despues de getline

	data->history[data->now_grep + 1] = data->input_line;
	data->now_grep++;
	return (0);
}

/**
 * save_history - guardar el archivo en el home
 * @p: ..
 * @o: ..
 * Return:..
 */
int save_history(data_of_program *data)
{
	guardar nuestro array al final del archivo
		for(i = grep +1;  ; i++)
		{
			write (to file) el array of strings;
		}

	close(/.simple_shell_history);

	return (0);
}

/**
 * read_history - read the file .simple_shell_history in the directory $HOME if it exists, and set the first line number to the total number of lines in the file modulo 4096
 * @p: ..
 * @o: ..
 * Return:..
 */
int read_history(void)
{
	llamar esta funcion desde initialize
		int nbytes;

	open(/.simple_shell_history; O_RDWR | O_CREAT |O_APPEND);
	bytes_read = read(fd, buf, nbytes);/* ?? */


	data->pre_grep = ;
	data->now_grep = 0;
	data->old_history = ;
	data->now_history= ;

	return (0);
}

/**
 * builtin_history - shows the history
 * @p: ..
 * @o: ..
 * Return:..
 */
int builtin_history(data_of_program *data)
{
	for(i = 0; ; i++)
	{
		print(i);
		print(cmd);
	}
	return (0);
}
