#include "shell.h"

/**
 * print_error - Displays error message
 * @usrinput: Input recieved from user
 * @count: Count of shell loop
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 */

void print_error(char *usrinput, int count, char **argv)
{
	char *per;

	PRINT(argv[0]);
	PRINT(": ");
	per = _itoa(count);
	PRINT(per);
	free(per);
	PRINT(": ");
	PRINT(usrinput);
	PRINT(": not found\n");
}

/**
 * error_file - Prints custom Error
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @z: Error Count
 */
void error_file(char **argv, int z)
{
	char *err = _itoa(z);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(err);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(err);
}


/**
 *  _prerror - Prints custom Error
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @z: Error Count
 * @cmnd: Array of parsed command strings
 */

void _prerror(char **argv, int z, char **cmnd)
{
	char *err = _itoa(z);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(err);
	PRINT(": ");
	PRINT(cmnd[0]);
	PRINT(": Illegal number: ");
	PRINT(cmnd[1]);
	PRINT("\n");
	free(err);
}


