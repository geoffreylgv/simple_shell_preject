#include "main.h"

/**
 * path - gets the command path
 * @rep: the path
 * @command: the command
 * Return: ptr
*/

char *path(char *rep, char *command)
{
	char **tokenized = NULL, *relative_path = NULL, *tmp = NULL, *token = NULL;
	int i = 0;
	size_t lenght= 0;

	if (rep == NULL)
		return (NULL);

	tmp = strtok(rep, "=");
	tmp = strtok(NULL, "=");

	tokenized = malloc(sizeof(char *) * 30);
	if (tokenized == NULL)
	{
		free(rep);
		return (NULL);
	}

	token = strtok(tmp, ":");
	while (token != NULL)
	{
		tokenized[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	tokenized[i] = NULL;
	i = 0;

	while (tokenized[i] != NULL)
	{
		lenght= strlen(tokenized[i]) + strlen(command) + 2;
		relative_path = malloc(lenght);
		strcpy(relative_path, tokenized[i]);
		strcat(relative_path, "/");
		strcat(relative_path, command);

		if (access(relative_path, X_OK) == 0)
		{
			free(tokenized);
			free(rep);
			return (relative_path);
		}
		free(relative_path);
		relative_path = NULL;
		i++;
	}

	free(tokenized);
	free(rep);
	return (NULL);
}
