#include "shell.h"

/**
 * print_number - Prints unsigned integers using _putchar function
 * @z: Unsigned integer to be printed
 */
void print_number(unsigned int z)
{
	unsigned int x = z;

	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * print_number_int - Prints integers using _putchar function
 * @z: Integer to be printed
 */
void print_number_int(int z)
{
	unsigned int x = z;

	if (z < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * echo_printer - Executes built-in echo function
 * @cmnd: Parsed Command
 * Return: 0 Upon Success -1 Upon Failure
 */
int echo_printer(char **cmnd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmnd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}


