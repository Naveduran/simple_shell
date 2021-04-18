#include "shell.h"
/**
 * read_history - read the file .simple_shell_history in the directory $HOME if it exists, and set the first line number to the total number of lines in the file modulo 4096
 * @o: ..
 * Return:..
 */
int read_history(data_of_program *data)
{
	int nbytes, i = 0, count = 0;
	char c = '\0';
	char *buf = '\0';

	if(fopen("/home/vagrant/.simple_shell_history", "r") == NULL)
	{
		printf("EL ARCHIVO NO EXISTE\n");
		printf("BUFFER=\"%s\"\n", buf);
	}
	if(fopen("/home/vagrant/.simple_shell_history", "r") == NULL)
	{
	data->file = fopen("/home/vagrant/.simple_shell_history", "ab+");
	fread(buf, 1, 20000, data->file);
	buf[str_length(buf)] = '\0';
	printf("BUFFER=\"%s\"\n", buf);
	for (i = 0; buf[i]; i++)
		if (buf[i] == '\n')
			count = count + 1;
	printf("i = %d\n", i);
	printf("count of lines= %i\n", count);
	data->pre_grep = count;
	printf("pre_grep = %i\n", data->pre_grep);
	data->new_history = malloc(sizeof(char *) * 4098);
	if (data->new_history == NULL)
	{
		perror("JERSON QUE ERROR VA AQUI? XD");
		return (-1);
	}
	}
	return (0);
}

/**
 * add_to_history - añadir array al history
 * @data: an structure with the program's data
 * Return: ..
 */
int add_to_history(data_of_program *data)
{
	data->new_history[data->exec_counter] = data->input_line;
	printf("GUARDE \"%s\" EN EL NUEVO ARRAY\n", data->input_line);
	return (0);
}

/**
 * save_history - guardar el archivo en el home
 * @data: ..
 * Return:..
 */
int save_history(data_of_program *data)
{
	int i;

	printf("I AM IN FUNCTION SAVE_HISTORY\n");
	for (i = 0; data->new_history[i]; i++)
	{
		printf("%d = %s\n", i, data->new_history[i]);
	}
	/* int i; */

	/* for(i = pre_grep;  ; i++) */
	/* { */
	/* 	fwrite (to file) el array of strings; */
	/* } */
	fclose(data->file);
	return (0);
}

/**
 * builtin_history - shows the history
 * @data: ..
 * Return:..
 */
int builtin_history(data_of_program *data)
{
/* 	for(i = 0; ; i++) */
/* 	{ */
/* 		print(i); */
/* 		print(cmd); */
/* 	} */
	return (0);
}
