#include "shell.h"

/**
 * _strcpy - makes a copy of a string.
 * @src: Is the original string.
 * @dest: Is the copy of the original
 *
 * Return: the copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
