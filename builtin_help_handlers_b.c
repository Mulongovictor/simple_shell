#include "shell.h"

/**
 * env_helper - Displays information on the shell by builtin command 'env'
 */
void env_helper(void)
{
	char *mesg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, mesg, _strlen(mesg));
}

/**
 * setenv_helper - Displays information on the shell by builtin
 * command 'setenv'
 */
void setenv_helper(void)
{
	char *mesg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
}

/**
 * unsetenv_helper - Displays information on the shellby builtin command
 * 'unsetenv'
 */
void unsetenv_helper(void)
{
	char *mesg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "message to stderr.\n";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
}

/**
 * display_helper - display help for builtin commands
 * @cmnd: parsed command
 * @st: Status of last command executed
 * Return: 0 Success
 */
int display_helper(char **cmnd, __attribute__((unused))int st)
{
	if (!cmnd[1])
		all_help();
	else if (_strcmp(cmnd[1], "alias") == 0)
		alias_help();
	else if (_strcmp(cmnd[1], "cd") == 0)
		cd_help();
	else if (_strcmp(cmnd[1], "exit") == 0)
		exit_help();
	else if (_strcmp(cmnd[1], "env") == 0)
		env_helper();
	else if (_strcmp(cmnd[1], "setenv") == 0)
		setenv_helper();
	else if (_strcmp(cmnd[1], "unsetenv") == 0)
		unsetenv_helper();
	else if (_strcmp(cmnd[1], "help") == 0)
		help_help();
	return (0);
}


