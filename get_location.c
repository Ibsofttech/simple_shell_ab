#include "main.h"
/**
 * get_location -clear is delcaration of function
 * @command: a command is pass as argument
 * Return: character
*/
char *get_location(char *command)
{
	char *path, *path_return;
	struct stat buf;

	if (stat(command, &buf) == 0)
	{
		return (command);
	}
	path = m_environ();
	path_return = path_process(path, command);
	if (path_return == NULL)
	{
		return (NULL);
	}

	return (path_return);
}
/**
 * m_environ - a function for PATH
 * Return: character
*/
char *m_environ()
{
	int i = 0;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			return (environ[i]);
		}
		i++;
	}
	return (NULL);
}

