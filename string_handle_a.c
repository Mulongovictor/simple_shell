#include "shell.h"

/**
 * _putchar - function that writes the character to stdout
 * @z: The character to print
 * Return: character to standard output
 */
int _putchar(char z)
{
	return (write(1, &z, 1));
}

/**
 * _puts - function that prints a string
 * @str: pointer to string
 * Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

/**
 * _strncpy - function that copies a string
 * @dest: destination string
 * @src: source string
 * @z: number of charaters to be copied
 * Return: copied strings
 */
char *_strncpy(char *dest, char *src, int z)
{
	int i = 0;

	while (i < z && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < z)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strlen - function that counts the length of a string
 * @z: string input
 * Return: length of string
 */
int _strlen(char *z)
{
	int i;

	for (i = 0; z[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _atoi - function to convert string to a integer
 * @z: string input
 * Return: converted integer
 */
int _atoi(char *z)
{
	int i = 0, j = 1, x;
	unsigned int l = 0;

	while (z[i] != '\0')
	{
		if (z[i] == '-')
		{
			return (2);
		}
		x = z[i] - '0';

		if (l > 0 && !(x >= 0 && x <= 9))
			break;

		if (x >= 0 && x <= 9)
			l = l * 10 + x;

		i++;
	}
	l *= j;
	return (l);
}


