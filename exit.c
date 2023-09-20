#include "main.h"
/**
 * my_exit - a the exit function
 * @args: to compare the input command with "exit"
 * Return: 1 if successful or 0 if failed
*/

int my_exit(char *args)
{
	if (strcmp(args, "exit") == 0)
	{
		free(args);
		return (1);
	}
	return(1);
}

