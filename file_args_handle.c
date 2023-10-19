#include "shell.h"

/**
 * file_read - Reads commands from the argument File
 * @file: File containing commands
 * @argv: Arguments passed
 * Return: -1 or 0
 */
void file_read(char *file, char **argv)
{
	FILE *fp;
	char *lines = NULL;
	size_t len = 0;
	int count = 0;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		error_file(argv, count);
		exit(127);
	}
	while ((getline(&lines, &len, fp)) != -1)
	{
		count++;
		file_treat(lines, count, fp, argv);
	}
	if (lines)
		free(lines);
	fclose(fp);
	exit(0);
}

/**
 * file_treat - Parse commands and handle their execution
 * @lines: Line from file
 * @count: Error counter
 * @fp: File descriptor
 * @argv: Command line arguments
 */
void file_treat(char *lines, int count, FILE *fp, char **argv)
{
	char **cmnd;
	int stat = 0;

	cmnd = parse_cmd(lines);
	if (_strncmp(cmnd[0], "exit", 4) == 0)
		exit_file_handle(cmnd, lines, fp);
	else if (check_builtin(cmnd) == 0)
	{
		stat = handle_builtin(cmnd, stat);
		free(cmnd);
	}
	else
	{
		stat = check_cmd(cmnd, lines, count, argv);
		free(cmnd);
	}
}

/**
 * exit_file_handle - Exit status handler for file input
 * @lines: Line from a file
 * @cmnd: Parsed command
 * @fd: File Descriptor
 */
void exit_file_handle(char **cmnd, char *lines, FILE *fd)
{
	int status;
	int i = 0;

	if (cmnd[i] == NULL)
	{
		free(lines);
		free(cmnd);
		fclose(fd);
		exit(errno);
	}
	while (cmnd[1][i])
	{
		if (_isalpha(cmnd[1][i++]) < 0)
			perror("Illegal number");
	}
	status = _atoi(cmnd[1]);
	free(lines);
	free(cmnd);
	fclose(fd);
	exit(status);
}


