#include "main.h"

/**
 * main - is a main function that accepts argument
 * @argc: a command argument count
 * @argv: a command argument vector
 * Return: integer
*/

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	char *line = NULL;
	char **args = NULL;
	size_t len = 0;
	int shell_exit = 0;

	while (1)
	{
		write(STDIN_FILENO, "simple_shell $> ", 17);

		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			exit(0);
		}
		rm_newline(line);
		rm_comment(line);
		shell_exit = my_exit(line);
		if (shell_exit == 1)
		{
			break;
		}
		_env(line);
		args = _strtok(line);
		if (args[0] == NULL)
		{
			free_args(args);
			continue;
		}
		execmd(args[0], args);
		free_args(args);
	}
	free(line);
	return (0);
}
