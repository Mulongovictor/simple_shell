#include "shell.c"

/**
 * is_deli - checks whether the char c is in the array of delimiters
 * @c: is the character to check against an array of delimiters
 * @arraydeli: is the array of separator(delimiter) characters
 *
 * Return: 1 if the char c is a delimiter, 0 if char c is not a delimiter
 */

int is_deli(char c, char *arraydeli)
{
	while (*arraydeli != '\0')
	{
		if (c == *arraydeli)
		{
			return (1);
		}
		arraydeli++;
	}
	return (0);
}
