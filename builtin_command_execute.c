#include "shell.h"

/**
 * change_dir - Changes directory
 * @cmnd: Parsed command
 * @st: Status of last command executed
 * Return: 0 on success 1 if failed (For OLDPWD Always 0 incase of no OLDPWD)
 */
int change_dir(char **cmnd, __attribute__((unused))int st)
{
	int value = -1;
	char cwdz[PATH_MAX];

	if (cmnd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmnd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmnd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwdz, sizeof(cwdz));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwdz, 1);
	}
	return (0);
}

/**
 * dis_env - Display enviroment variable
 * @cnd: parsed command
 * @st: status of last command executed
 * Return: Always 0
 */
int dis_env(__attribute__((unused)) char **cnd, __attribute__((unused)) int st)
{
	size_t i;
	int leng;

	for (i = 0; environ[i] != NULL; i++)
	{
		leng = _strlen(environ[i]);
		write(1, environ[i], leng);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * echo_bul - execute echo cases
 * @st: statue of last command executed
 * @cmnd: parsed command
 * Return: Always 1 Or execute normal echo
 */
int echo_bul(char **cmnd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(cmnd[1], "$?", 2) == 0)
	{
		print_number_int(st);
		PRINT("\n");
	}
	else if (_strncmp(cmnd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINT("\n");
	}
	else if (_strncmp(cmnd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINT(path);
		PRINT("\n");
		free(path);
	}
	else
		return (print_echo(cmnd));

	return (1);
}

/**
 * history_dis - display history of user input on simple_shell
 * @a: parsed command
 * @st: status of last command executed
 * Return: 0 success or -1 if fail
 */
int history_dis(__attribute__((unused))char **a, __attribute__((unused))int st)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *fstline = NULL;
	size_t len = 0;
	int counter = 0;
	char *per;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&fstline, &len, fp)) != -1)
	{
		counter++;
		per = _itoa(counter);
		PRINT(per);
		free(per);
		PRINT(" ");
		PRINT(fstline);
	}
	if (fstline)
		free(fstline);
	fclose(fp);
	return (0);
}


