#include "shell.h"

/**
 * _strdup - creates a duplicate of the given string
 * @string: is the string to be duplicated.
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *string)
{
	size_t length;
	char *duplicate;

	if (string == NULL)
	{
		return (NULL);
	}
	length = _strlen(string);
	duplicate = malloc(sizeof(char) * (length + 1));
	if (duplicate != NULL)
	{
		_strcpy(duplicate, string);
	}
	return (duplicate);
}
