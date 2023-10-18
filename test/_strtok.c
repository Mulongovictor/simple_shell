#include "shell.h"

/**
 * _strtok - tokenizes a string according to a certain delimiter
 * it doesn't create a new string to hold the tokens but rather remembers
 * what the previous string was when faced with a NULL pointer.
 * for example if you have a string str = "helo; now; bo"
 * when _strtok is called for the first time (_strtok(str, ";")),
 * it will return hello and when it is called for the second time
 * (_strtok(NULL, ";");)it will return now..
 *
 * @str: the string to be tokenized
 * @deli: the delimiter to separate tokens
 *
 * Return: a character pointer to the  current delimited token
 */
char *_strtok(char *str, char *deli);

char *_strtok(char *str, char *deli)
{
	static char *store;
	char *start;

	if (str == NULL)
	{
		str = store;

	}
	if (str == NULL)
	{
		return (NULL);
	}

	while (1)
	{
		if (is_deli(*str, deli))
		{
			str++;
			continue;
		}
		if (*str == '\0')
		{
			return (NULL);
		}
		break;
	}
	start = str;

	while (1)
	{
		if (*str == '\0')
		{
			store = str;
			return (start);
		}
		if (is_deli(*str, deli))
		{
			*str = '\0';
			store = str + 1;
		}
		str++;
	}
}
