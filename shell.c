#include "shell.h"
/**
 * main - mimicks the operation of a ./sh
 *
 * Return: 0 Always for Success
 */

int main(void);
int main(void)
{
	char *prompt = "$ ";
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
		if (interactive != 0)
			write(1, prompt, _strlen(prompt));
		bytesgot = getline(&usercommand, &buffersize, stdin);
		if (bytesgot == -1)
		{
			write(1, "\n", 1);
			free(ptr);
			exit(0);
		}
		i = 0;
		count = 0;
		ptr = malloc(sizeof(char *) * 20);

		portion = strtok(usercommand, delim);

		while (portion != NULL)
		{
			ptr[i] = malloc(sizeof(char) * (_strlen(portion) + 1));
			_strcpy(ptr[i], portion);
			i++;
			count++;
			portion = strtok(NULL, delim);
		}
		ptr[i] = NULL;

		if (i == 0)
		{
			continue;
		}

		if (strcmp(ptr[0], "exit") == 0)
		{
			free(ptr[0]);
			break;
		}
		printf("%d\n",count);

		child_path = path_find(ptr[0]);
		if (child_path == NULL)
		{
			perror("Command Not Found");
			free(ptr);
			continue;
		}

		child_process = fork();

		if (child_process == 0)
		{
			execve(child_path, ptr, environ);
			if (execve(child_path, ptr, environ) == -1)
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
		if (interactive == 0)
			break;
	}
	free(ptr);
	if (usercommand != NULL)
	{
		free(usercommand);
	}

	return (0);
}

