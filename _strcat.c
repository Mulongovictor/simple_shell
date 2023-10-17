#include "shell.h"

/**
 * _strcat - joins two strings together
 * @desti: is the string that is added to another string
 * @src: is
 *
 * Return: Returns a pointer to the string
 */

char *_strcat(char *desti, const char *src)
{
	size_t i = 0, j = 0;

	for (j = 0; desti[j] != '\0'; j++)
	{

	}
	for (i = 0; src[i] != '\0'; i++)
	{
		desti[j] = src[i];
		j++;
	}
	desti[j] = '\0';
	return (desti);
}
