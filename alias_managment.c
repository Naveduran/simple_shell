#include "shell.h"

/**
 * print_alias - add, remove or show aliases
 * @data: struct for the program's data
 * @alias: name of the alias to be printed
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int print_alias(data_of_program *data, char *alias)
{
	int i = 0;

	if (alias == NULL)
	{/*prints all aliases variables*/
		if (data->alias_list)
		{
			for (; data->alias_list[i]; i++)
			{
				_print(data->alias_list[i]);
				_print("\n");
			}
		}
	}
	else
	{/* prints the alias name */
		if (data->alias_list)
		{
			for (; data->alias_list[i]; i++)
			{
				if (str_compare(data->alias_list[i], alias, str_length(alias)))
				{
					_print(data->alias_list[i]);
					_print("\n");
					return (0);
				}
			}
		}
	}
	return (0);
}

/**
 * get_alias - add, remove or show aliases
 * @data: struct for the program's data
 * @alias: name of the request alias.
 * Return: zero if sucess, or other number if its declared in the arguments
 */
char *get_alias(data_of_program *data, char *alias)
{
	int i, alias_length = 0;

	/* validate the arguments */
	if (alias == NULL || data->alias_list == NULL)
		return (NULL);

	/* obtains the leng of the variable requested */
	alias_length = str_length(alias);

	for (i = 0; data->alias_list[i]; i++)
	{/* Iterates through the environ and check for coincidence of the vame */
		if (str_compare(alias, data->alias_list[i], alias_length) &&
		 data->alias_list[i][alias_length] == '=')
		{/* returns the value of the key NAME=  when find it*/
			return (data->alias_list[i] + alias_length + 1);
		}
	}
	/* returns NULL if did not find it */
	return (NULL);

}

/**
 * set_alias - add, or override alias
 * @alias_string: alias to be seted in the form (name='value')
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int set_alias(char *alias_string, data_of_program *data)
{
	int i;
	char buffer[50] = {'0'};

	/* validate the arguments */
	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);

/* Iterates ALIAS TO FIND THE = SIMBOL */
	for (i = 0; alias_string[i]; i++)
	{
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
			break;
	}

	/* Iterates through the alias list and check for coincidence of the varnAme */
	for (i = 0; data->alias_list[i]; i++)
	{
		if (str_compare(buffer, data->alias_list[i], str_length(buffer)))
		{
			free(data->alias_list[i]);
			data->alias_list[i] = str_duplicate(alias_string);
			return (0);
		}

	}
	data->alias_list[i] = str_duplicate(alias_string);
	return (0);
}
