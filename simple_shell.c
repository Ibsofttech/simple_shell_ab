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
	int line_len;

	while (1)
	{
		write(STDIN_FILENO, "simple_shell $> ", 17);

		if (getline(&line, &len, stdin) == -1)
		{
			write(STDOUT_FILENO, "\nExiting simple_shell.\n", 24);
			free(line);
			exit(0);
		}
		line_len = strlen(line);
		if (line_len > 0 && line[line_len - 1] == '\n')
			line[line_len - 1] = '\0';
		my_exit(line);
		_env(line);
		args = _strtok(line);
		if (args[0] == NULL)
		{
			free(args);
			continue;
		}
		if (args != NULL)
		{
			execmd(args[0], args);
			free(args);
		}
	}
}

