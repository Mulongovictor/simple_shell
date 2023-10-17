#include "shell.h"

/**
 * _strlen - counts the number of characters in a string
 * @str: is the pointer to the string whose length is counted
 * Return: the size of the string count.
 */

int _strlen(char *str)
{
	int i, countchar = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		countchar++;
	}
	return (countchar);
}
