#include "main.h"

/**
 * _env - a function that prints the environment variables
 * @line: a command
 * Retrun: NULL
*/
void _env(char *line)
{
	int i;

	if (_strcmp(line, "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
	}
}
