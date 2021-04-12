#include "shell.h"

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

char *env_set_key(char *key, char *value, data_of_program *data)
{
	int i, key_length = 0, is_new_key = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (NULL);

	key_length = str_length(key);

	/* iterates through the environ */
	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length))
		{/* if key already exists */
			is_new_key = 0;
			break;
		}
	}
	free(data->env[i]);
	data->env[i] = str_concat(str_duplicate(key), "=");
	data->env[i] = str_concat(data->env[i], value);

	if (is_new_key)
	{
		data->env[i + 1] = NULL;
	}

	return (data->env[i]);
}

/**
 * 
 * 
 * Return: 1 if the key was removed, 0 if the key doesnot exist;
 */
int env_remove_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (0);
	key_length = str_length(key);

	/* iterates through the environ */
	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length))
		{/* if key already exists, remove them */
			free(data->env[i]);
			/*move the others keys one position down.*/
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
