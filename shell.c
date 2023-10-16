#include "shell.h"

int main();
int main()
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
			if (execve(ptr[0], ptr, NULL) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else if (child_process < 0)
		{
			free(ptr);
			perror("fork failed");
			exit(EXIT_FAILURE);
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

