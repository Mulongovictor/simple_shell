#include "shell.h"

/**
 * tokenizer - Separates command recieved from stdin by ;
 * @usrinput: String gathered from stdin
 * Return: Parsed strings to be used as commands
 */
char **tokenizer(char *usrinput)
{
	char **cmdstring;
	char *command;
	int i;
	int buffsize = BUFSIZE;

	if (usrinput[0] == ' ' && usrinput[_strlen(usrinput)] == ' ')
		exit(0);
	if (usrinput == NULL)
		return (NULL);
	cmdstring = malloc(sizeof(char *) * buffsize);
	if (!cmdstring)
	{
		free(cmdstring);
		perror("hsh");
		return (NULL);
	}
	command = _strtok(usrinput, ";&\n");
	for (i = 0; command; i++)
	{
		cmdstring[i] = command;
		command = _strtok(NULL, ";&\n");
	}
	cmdstring[i] = NULL;

	return (cmdstring);
}


