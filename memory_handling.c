#include "shell.h"

/**
 * _realloc -  reallocates a memory block as aheap  using malloc and free
 *@ptr: pointer to a pointer of addresses
 *@previous_size: previous Size Of The Pointer
 *@next_size: new size of the pointer
 *Return: Pointer to reallocated memory
 */
void *_realloc(void *ptr, unsigned int previous_size, unsigned int next_size)
{
	void *results;

	if (next_size == previous_size)
		return (ptr);
	if (next_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	results = malloc(next_size);
	if (results == NULL)
	{
		free(results);
		return (NULL);
	}
	if (ptr == NULL)
	{
		filling_array(results, '\0', next_size);
		free(ptr);
	}
	else
	{
		_memocpy(results, ptr, previous_size);
		free(ptr);
	}
	return (results);
}

/**
 * all_freed - free memory allocated
 * @cmnd: array pointer
 * @lines: char pointer
 * Return: Void
 */
void all_freed(char **cmnd, char *lines)
{
	free(cmnd);
	free(lines);
	cmnd = NULL;
	lines = NULL;
}

/**
 * _memocpy - copy bytes of memory from source to destination
 *@dest: destination pointer
 *@src: source pointer
 *@z: size to be copied
 *Return: pointer to destination
 */
char *_memocpy(char *dest, char *src, unsigned int z)
{
	unsigned int i;

	for (i = 0; i < z; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * filling_array - fill an array by constant byte
 *@z: void pointer
 *@y: int
 *@len: length for int
 *Return: void pointer
 */
void *filling_array(void *z, int y, unsigned int len)
{
	char *p = z;
	unsigned int i = 0;

	while (i < len)
	{
		*p = y;
		p++;
		i++;
	}
	return (z);
}

/**
 * _calloc - allocates memory for an array using malloc
 *@size: size
 *Return: void pointer
 */
void *_calloc(unsigned int size)
{
	char *x;
	unsigned int i;

	if (size == 0)
		return (NULL);
	x = malloc(size);
	if (x == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		x[i] = '\0';
	}
	return (x);
}


