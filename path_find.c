#include "shell.h"

/**
 * path_cmnd -  Search In $PATH for executable command
 * @cmnd: Parsed input
 * Return: 0 on success or  1 on failure  0
 */
int path_cmnd(char **cmnd)
{
	char *path, *value, *cmnd_dir;
	struct stat buff;

	path = _getenv("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		cmnd_dir = builder(*cmnd, value);
		if (stat(cmnd_dir, &buff) == 0)
		{
			*cmnd = _strdup(cmnd_dir);
			free(cmnd_dir);
			free(path);
			return (0);
		}
		free(cmnd_dir);
		value = _strtok(NULL, ":");
	}
	free(path);
	free(value);
	return (1);
}

/**
 * builder - Build command
 * @tok: Executable command
 * @value: Directory conatining Command
 * Return: Parsed full path of command or NULL if failed
 */
char *builder(char *tok, char *value)
{
	char *cmnd;
	size_t len;

	len = _strlen(value) + _strlen(tok) + 2;
	cmnd = malloc(sizeof(char) * len);
	if (cmnd == NULL)
	{
		free(cmnd);
		return (NULL);
	}

	memset(cmnd, 0, len);

	cmnd = _strcat(cmnd, value);
	cmnd = _strcat(cmnd, "/");
	cmnd = _strcat(cmnd, tok);

	return (cmnd);
}

/**
 * _getenv - Gets the value of environment variable by name
 * @name: Environment variable name
 * Return: The value of the environment variable or NULL if failed
 */
char *_getenv(char *name)
{
	size_t name_length, value_length;
	char *value;
	int i, j, x;

	name_length = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], name_length) == 0)
		{
			value_length = _strlen(environ[i]) - name_length;
			value = malloc(sizeof(char) * value_length);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = name_length + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}
	return (NULL);
}


