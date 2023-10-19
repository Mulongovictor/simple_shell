#include "shell.h"

/**
 * all_help - Displays all possible builtin shellby commands
 */
void all_help(void)
{
	char *mesg = "Shellby\nThese shell commands are defined internally.\n";

	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "Type 'help' to see this list.\nType 'help name' to find ";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "out more about the function 'name'.\n\n  alias   \t";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
}

/**
 * alias_help - Displays information on the shell by builtin command 'alias'
 */
void alias_help(void)
{
	char *mesg = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "\n\talias: Prints a list of all aliases, one per line, in ";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = " the aliases name, name2, etc. one per line, in the ";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = " an alias for each NAME whose VALUE is given. If NAME ";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "is already an alias, replace its value with VALUE.\n";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
}

/**
 * cd_help - Displays information on the shell by builtin command 'cd'
 */
void cd_help(void)
{
	char *mesg = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "command is interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = " given, the command is interpreted as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "\tThe environment variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "after a change of directory.\n";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
}

/**
 * exit_help - Displays information on the shell by builtin command 'exit'
 */
void exit_help(void)
{
	char *mesg = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = " exit 0.\n";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
}

/**
 * help_help - Displays information on the shell by builtin command 'help'
 */
void help_help(void)
{
	char *mesg = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
	mesg = "builtin command.\n";
	write(STDOUT_FILENO, mesg, _strlen(mesg));
}


