#include "shell.h"

/**
 * _getenv - This returns the string array copy of our environ
 * @variable: The structure that contains potential arguments, To maintain
 * constant function prototype
 * Return: Always (0)
 */

char *_getenv(char *variable)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, ":");
		if (key != NULL && _strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			if (value != NULL)
			{
			env = _strdup(value);
			free(tmp);
			return (env);
			}
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
