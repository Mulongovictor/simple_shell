#include "header.h"

/**
 * check_delim - function that checks if a character matchs any character
 * @c: character to check
 * @str: string of delimiters
 * Return: 1 on success, 0 on failure
 */
unsigned int is_delim(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - function that extracts tokens of a string
 * @str1: string
 * @delim: delimiter
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *str1, const char *delim)
{
	static char *toks;
	static char *ntoks;
	unsigned int i;

	if (str1 != NULL)
		ntoks = str1;
	toks = ntoks;
	if (toks == NULL)
		return (NULL);
	for (i = 0; toks[i] != '\0'; i++)
	{
		if (is_delim(toks[i], delim) == 0)
			break;
	}
	if (ntoks[i] == '\0' || ntoks[i] == '#')
	{
		ntoks = NULL;
		return (NULL);
	}
	toks = ntoks + i;
	ntoks = toks;
	for (i = 0; ntoks[i] != '\0'; i++)
	{
		if (is_delim(ntoks[i], delim) == 1)
			break;
	}
	if (ntoks[i] == '\0')
		ntoks = NULL;
	else
	{
		ntoks[i] = '\0';
		ntoks = ntoks + i + 1;
		if (*ntoks == '\0')
			ntoks = NULL;
	}
	return (toks);
}

