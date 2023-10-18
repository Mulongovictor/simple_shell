#include "shell.h"

/**
 * is_builtin - Checks if parsed command in built-in
 * @cmnd: Parsed command to be check
 * Return: 0 Succes -1 Fail
 */
int is_builtin(char **cmnd)
{
	builtin fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*cmnd == NULL)
	{
		return (-1);
	}
	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * handle_builtin - Handles predefined built in commands
 * @cmnd: Array of parsed command strings
 * @st: Status of last execution
 * Return: -1 Failure 0 Success
 */
int handle_builtin(char **cmnd, int st)
{
	builtin built_in[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((built_in + i)->command)
	{
		if (_strcmp(cmnd[0], (built_in + i)->command) == 0)
		{
			return ((built_in + i)->function(cmnd, st));
		}
		i++;
	}
	return (-1);
}

/**
 * exit_bul - Exit Status for built-in commands
 * @cmnd: Array of parsed command strings
 * @input: Input recieved from user (to be freed)
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @z: Shell execution count
 * @stat: Exit status
 */
void exit_bul(char **cmnd, char *input, char **argv, int z, int stat)
{
	int status, i = 0;

	if (cmnd[1] == NULL)
	{
		free(input);
		free(cmnd);
		exit(stat);
	}
	while (cmnd[1][i])
	{
		if (_isalpha(cmnd[1][i++]) != 0)
		{
			_prerror(argv, z, cmd);
			free(input);
			free(cmnd);
			exit(2);
		}
		else
		{
			status = _atoi(cmnd[1]);
			if (status == 2)
			{
				_prerror(argv, z, cmnd);
				free(input);
				free(cmnd);
				exit(status);
			}
			free(input);
			free(cmnd);
			exit(status);

		}
	}
}


