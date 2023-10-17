#include "shell.h"

/**
 * _strdup - creates a duplicate of the given string
 * @string: is the string to be duplicated.
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *string)
{
	if (string == NULL)
	{
		return (NULL);
	}
	size_t length = strlen(string);
	char *duplicate = malloc(sizeof(char) * (length + 1));

	if (duplicate != NULL)
	{
		_strcpy(duplicate, string);
	}
	return (duplicate);
}
