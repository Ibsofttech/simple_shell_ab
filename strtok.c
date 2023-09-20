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

	input_copy = strdup(input);
	if (input_copy == NULL)
	{
		free(input_copy);
		return (NULL);
	}
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
		strcpy(args[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	args[i] = NULL;

	free(input_copy);
	return (args);
}

