#include "shell.h"

/**
 * path_find - This takes the tokenized string as argument and call it command
 * @command: is the string that is concatenated with a /bin/
 *
 * Return: the two concatenated strings if they are executable
 * or NULL if the two joined strings are not accessible
 */

char *path_find(char *command);
char *path_find(char *command)
{
	char *pathenv;
	char *fullcommand;
	char *directory;
	struct stat filedetails;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &filedetails) == 0)
			{
				return (strdup(command));
			}
			return (NULL);
		}
	}

	pathenv = _getenv("PATH");

	if (!pathenv)
	{
		return (NULL);
	}
	directory = _strtok(pathenv, ":");

	while (directory)
	{
		fullcommand = malloc(_strlen(directory) + _strlen(command) + 2);

		if (fullcommand)
		{
			_strcpy(fullcommand, directory);
			strcat(fullcommand, "/");
			strcat(fullcommand, command);
			if (stat(fullcommand, &filedetails) == 0)
			{
				free(pathenv);
				return (fullcommand);
			}
			free(fullcommand), fullcommand = NULL;

			directory = _strtok(NULL, ":");
		}
	}
	free(pathenv);
	return (NULL);
}
