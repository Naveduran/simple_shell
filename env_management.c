#include "shell.h"

/**
 * env_get_key - gets the value of an environment variable
 * @name: the environment variable of interest
 * @data: struct of the program's data
 * Return: a pointer to the value of the variable or NULL if it doesn't exist
 */
char *env_get_key(char *name, data_of_program *data)
{
	int i, name_length = 0;

	if (name == NULL || data->env == NULL)
		return (NULL);

	name_length = str_length(name);
	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(name, data->env[i], name_length))
		{/*return the value of the key NAME=*/
			return(data->env[i] + name_length + 1);
		}
	}
	return (NULL);
}

/**
 * env_set_key - overwrite the value of the environment variable
 * @key: name of the variable to set
 * @value: new value
 * @data: struct of the program's data
 * Return: 1 if the parameters are NULL, 2 if there is an erroror 0 if sucess.
 */

int env_set_key(char *key, char *value, data_of_program *data)
{
	int i, key_length = 0, is_new_key = 1;

	if (key == NULL || value == NULL || data->env == NULL)
	{
		return(1);
	}
	key_length = str_length(key);

	for (i = 0; data->env[i]; i++)
	{/* Iterates through the environ */
		if (str_compare(key, data->env[i], key_length))
		{/* If key already exists */
			is_new_key = 0;
			free(data->env[i]);
			break;
		}
	}
	data->env[i] = str_concat(str_duplicate(key), "=");
	data->env[i] = str_concat(data->env[i], value);
/**** hay que confirmar que strconcat funcionó? ****/
	if (is_new_key)
	{
		data->env[i + 1] = NULL;
	}
	return (0);
}

/**
 * env_remove_key - remove a key from the environment file
 * @key: the key to remove
 * @data: the sructure of the program's data
 * Return: 1 if the key was removed, 0 if the key does not exist;
 */
int env_remove_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (0);
	key_length = str_length(key);

	for (i = 0; data->env[i]; i++)
	{/* iterates through the environ */
		if (str_compare(key, data->env[i], key_length))
		{/* if key already exists, remove them */
			free(data->env[i]);/* move the others keys one position down */
			i++;
			for (; data->env[i]; i++)
			{
				data->env[i - 1]= data->env[i];
			}
			data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}
