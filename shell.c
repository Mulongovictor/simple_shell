#include "shell.h"
/**
 * main - mimicks the operation of a ./sh
 *
 * Return: 0 Always for Success
 */

int main(void);
int main(void)
{
	char *prompt = "victor&ritashell$ ";
	char *usercommand = NULL;
	char **ptr;
	char *portion;
	size_t buffersize = 0;
	ssize_t bytesgot = 0;
	char *delim = " \n\t";
	pid_t child_process;
	int status;
	int i;
	int j;
	int count;
	int interactive = 1;
	char *child_path;

	while (1)
	{
		interactive = isatty(STDIN_FILENO);
		if (interactive == 1)
			write(1, prompt, _strlen(prompt));

		bytesgot = getline(&usercommand, &buffersize, stdin);

		ptr = (char **)malloc(sizeof(char *) * 20);
		i = 0;
		count = 0;

		portion = _strtok(usercommand, delim);

		while (portion != NULL)
		{
			ptr[i] = (char *)malloc(_strlen(portion) + 1);
			_strcpy(ptr[i], portion);
			i++;
			count++;
			portion = _strtok(NULL, delim);
		}
		if (interactive != 1)
			break;
		ptr[i] = NULL;

		if (i == 0)
		{
			continue;
		}

		if (strcmp(ptr[0], "exit") == 0)
		{
			write(1, "Exiting shell...\n", _strlen("Exiting shell...\n"));
			free(ptr[0]);
			break;
		}

		if (bytesgot == -1)
		{
			write(1, "Exiting shell...\n", _strlen("Exiting shell...\n"));
			break;
		}

		child_process = fork();

		if (child_process == 0)
		{
			child_path = path_find(usercommand[0]);

			if (child_path == NULL)
			{
				perror("Command Not Found");
				exit(1);
			}

			execve(child_path, usercommand, environ);
			if (execve(child_path, usercommand, environ) == -1)
			{
				perror("Error: Failed to execute the program");
				exit(EXIT_FAILURE);
			}
		}
		else if (child_process < 0)
		{
			free(ptr);
			perror("fork failed");
			return (-1);
		}
		else
		{
			wait(&status);
		}

		for (j = 0; j < i; j++)
		{
			free(ptr[j]);
		}
	}
	free(ptr);

	if (usercommand != NULL)
	{
		free(usercommand);
	}

	return (0);
}

