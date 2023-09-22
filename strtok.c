#include "main.h"

/**
 * _strtok - to tokenalise the input from getline function
 * @input: a command
 * Return: arraye of string
*/
char **_strtok(char *input)
{
	char *input_copy = NULL, *token = NULL;
	char *delim = " ";
	int num_token = 0, i = 0;
	char **args = NULL;

	input_copy = _strdup(input);
	token = strtok(input, delim);
	while (token != NULL)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	num_token++;
	args = malloc(sizeof(char *) * num_token);
	if (args == NULL)
	{
		free(args);
		free(input_copy);
		return (NULL);
	}
	token = NULL;
	token = strtok(input_copy, delim);
	while (token != NULL)
	{
		args[i] = malloc(sizeof(char *) * (strlen(token) + 1));
		if (args[i] == NULL)
		{
			free_args(args);
			free(input_copy);
			return (NULL);
		}
		strcpy(args[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	args[i] = NULL;

	free(input_copy);
	return (args);
}

/**
 * free_args - function that free args allocated space
 * @args: memory allocated
 * Return: null
*/

void free_args(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
	{
		free(args[i]);
	}
	free(args);
}

