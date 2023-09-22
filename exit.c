#include "main.h"
/**
 * my_exit - a the exit function
 * @args: to compare the input command with "exit"
 * Return: 1 if successful or 0 if failed
*/

int my_exit(char *args)
{
	if (_strcmp(args, "exit") == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
