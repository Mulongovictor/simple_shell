#include "shell.h"

/**
 * _strchr - searches for a particular character in a string
 * and returns a pointer to the first occurance of the character.
 * @s: is the string to examine occurance of a particular char.
 * @a: is the character searched for in the string.
 *
 * Return: a pointer to the first occurance of the character
 * in the string.
 */

char *_strchr(const char *s, int a)
{
	if (s == NULL)
	{
		return (NULL);
	}
	while (*s != '\0')
	{
		if (*s == a)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
