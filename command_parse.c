#include "shell.h"

/**
 * parse_cmd - Parses the command recieved from stdin
 * @input: String gathered from stdin
 * Return: Parsed strings to be used as arguments
 */
char **parse_cmd(char *input)
{
	char **argmts;
	char *argument;
	int i;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	argmts = malloc(sizeof(char *) * buffsize);
	if (!argmts)
	{
		free(argmts);
		perror("hsh");
		return (NULL);
	}
	argument = _strtok(input, "\n\t\r\a ");
	for (i = 0; argument; i++)
	{
		argmts[i] = argument;
		argument = _strtok(NULL, "\n\t\r\a ");
	}
	argmts[i] = NULL;

	return (argmts);
}


