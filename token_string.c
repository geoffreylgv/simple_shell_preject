#include "main.h"

/**
 * token_string - function that dynamycaly tokenizes the string
 * @command: command the user entered
 * Return: pointer of a pointer
 */

char **token_string(char *command)
{
	int i = 0;
	char *delim = " \n";
	char *token = NULL;
	char **tokens = NULL;/*list of token*/

	tokens = malloc(sizeof(char *) * 25);
	if (tokens == NULL)
		return (NULL);

	token = strtok(command, delim);

	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}

	tokens[i] = NULL;
	return (tokens);
}
