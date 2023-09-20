#include "main.h"

/**
 * execmd - A function that executes a command
 * @command: the command to be executed
 * @args: array of strings containning the command
 * Return: -1 if failed and 0 if successful
*/

int execmd(char *command, char **args)
{
	pid_t child_pid;
	int status, exec_return;
	char *main_command = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}

	else if (child_pid == 0)
	{
		main_command = get_location(command);
		if (main_command == NULL)
		{
			perror("./hsh");
			return (0);
		}
		exec_return = execve(main_command, args, NULL);
		if (exec_return == -1)
		{
			perror("./hsh");
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
	}
}
