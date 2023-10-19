#include "shell.h"

/**
 * enviro_creation - Creates an array of Enviroment Variables
 * @enviro: Array to store Enviroment Variables
 */

void enviro_creation(char **enviro)
{
	int i;

	for (i = 0; environ[i]; i++)
		enviro[i] = _strdup(environ[i]);
	enviro[i] = NULL;
}

/**
 * enviro_free - Frees the memory of the created Enviroment Variables array
 * @enviro:  Array of Environment variables
 */
void enviro_free(char **enviro)
{
	int j;

	for (j = 0; enviro[j]; j++)
	{
		free(enviro[j]);
	}
}


