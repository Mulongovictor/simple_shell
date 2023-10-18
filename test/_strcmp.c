#include "shell.h"

/**
 * _strcmp - compares if two strings are the same.
 * @s1: string1
 * @s2: string2
 *
 * Return: 0 if strings are similar, 1 if s1>s2 and
 * -1 if s1<s2 in ascii code value for char
 */

int _strcmp(char *s1, char *s2)
{
	int status;

	while ((*s1 != '\0' && *s2 != '\0') && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		status = 0;
	}
	else if (*s1 > *s2)
	{
		status = 1;
	}
	else
	{
		status = -1;
	}
	return (status);
}
