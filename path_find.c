#include "shell.h"

/**
 * path_find - This takes the tokenized string as argument and call it command
 * @command: is the string that is concatenated with a /bin/
 *
 * Return: the two concatenated strings if they are executable
 * or NULL if the two joined strings are not accessible
 */

char *path_find(char *command)
{
	char *path = getenv("PATH");
	char *path_dup = strdup(path);
	char *strarg;

	strarg = strtok(path_dup, ":");

	while (strarg != NULL)
	{
		char *str = malloc(strlen(strarg) + strlen(command) + 2);

		sprintf(str, "%s/%s", strarg, command);

		if (access(str, X_OK) == 0)
		{
			free(path_dup);
				return (str);
		}
		free(str);
		strarg = strtok(NULL, ":");
	}
	free(path_dup);
	return (NULL);
}
