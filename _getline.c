#include "shell.h"

/**
 * _getline - read input from standard input by user
 * Return: the input on a buffer
 */
char *_getline()
{
	int j, rd, buffsize = BUFSIZE;
	char a = 0, *buffered, *buff;

	buffered = malloc(buffsize);
	if (buffered == NULL)
	{
		free(buffered);
		return (NULL);
	}
	for (j = 0; a != EOF && a != '\n'; j++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &a, 1);
		if (rd == 0)
		{
			free(buffered);
			exit(EXIT_SUCCESS);
		}
		buffered[j] = a;
		if (buffered[0] == '\n')
			return (enter(buffered));
		if (j >= buffsize)
		{
			buffered = realloc(buffered, (buffsize + 2));
			if (buffered == NULL)
			{
				free(buffered);
				return (NULL);
			}
		}
	}
	buffered[j] = '\0';
	buff = space(buffered);
	free(buffered);
	hashtag_handler(buff);
	return (buff);
}

/**
 * enter - Handles newline character input
 * @strng: String to be handled
 * Return: Empty string
 */
char *enter(char *strng)
{
	free(strng);
	return ("\0");
}

/**
 * space - Modifies the input string to remove preceeding whitespaces
 * @strz: Input to be modifies
 * Return: Returns the modified string
 */
char *space(char *strz)
{
	int i, j = 0;
	char *buffa;

	buffa = malloc(sizeof(char) * (_strlen(strz) + 1));
	if (buffa == NULL)
	{
		free(buffa);
		return (NULL);
	}
	for (i = 0; strz[i] == ' '; i++)
		;
	for (; strz[i + 1] != '\0'; i++)
	{
		buffa[j] = strz[i];
		j++;
	}
	buffa[j] = '\0';
	if (buffa[0] == '\0' || buffa[0] == '#')
	{
		free(buffa);
		return ("\0");
	}
	return (buffa);
}

/**
 * hashtag_handler - function that removes everything after '#'
 * @buffiz: input buffer
 * Return: nothing
 */
void hashtag_handler(char *buffiz)
{
	int i;

	for (i = 0; buffiz[i] != '\0'; i++)
	{
		if (buffiz[i] == '#' && buffiz[i - 1] == ' ' && buffiz[i + 1] == ' ')
		{
			buffiz[i] = '\0';
		}
	}
}

