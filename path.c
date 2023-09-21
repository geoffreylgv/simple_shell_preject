#include "main.h"

/**
 * tokenize_path - the PATH	environment	variable into an array of strings.
 * @rep: The PATH environment variable.
 * Return: An array	of strings containing the individual paths in
 * the PATH	environment	variable, or NULL if an error occurred.
 */
char **tokenize_path(char *rep)
{
	int		i =		0;
	char **tokenized = malloc(sizeof(char *) * 30);
	char *token = strtok(rep, ":");

	if (tokenized == NULL)
	{
		free(rep);
		return (NULL);
	}

	while (token != NULL)
	{
		tokenized[i] = token;
		token =	strtok(NULL, ":");
		i++;
	}
	tokenized[i] = NULL;

	return (tokenized);
}

/**
 * check_file_exists_and_is_executable - Check if the file exists
 * and is executable.
 * @file_path: The path	to the file.
 * Return: 1 if the		file exists		and		is executable, 0 otherwise.
 */
int check_file_exists_and_is_executable(char *file_path)
{
	return (access(file_path, X_OK)	== 0);
}

/**
 * construct_full_path - Construct a full path from a
 * relative path and a command name.
 * @relative_path: The relative	path.
 * @command: The command name.
 * Return: A full path to the command, or NULL if an error occurred.
 */
char *construct_full_path(char *relative_path, char *command)
{
	size_t length =	strlen(relative_path) +	strlen(command)	+ 2;
	char *full_path	= malloc(length);

	if (full_path == NULL)
	{
		free(full_path);
		return (NULL);
	}

	strcpy(full_path, relative_path);
	strcat(full_path, "/");
	strcat(full_path, command);

	return (full_path);
}

/**
 * path	- Find the path	to a command.
 * @rep: The PATH environment variable.
 * @command: The command name.
 * Return: The path		to the command,	or NULL	if the command does
 * not exist or is not executable.
 */
char *path(char	*rep, char *command)
{
	char **tokenized = tokenize_path(rep);
	int i = 0;

	if (tokenized == NULL)
	{
		free(command);
		return (NULL);
	}

	while (tokenized[i]	!= NULL)
	{
		char *full_path	= construct_full_path(tokenized[i],	command);

		if (full_path == NULL)
		{
			free(tokenized);
			return (NULL);
		}

		if (check_file_exists_and_is_executable(full_path))
		{
			free(tokenized);
			free(rep);
			return (full_path);
		}
		free(full_path);
		full_path =	NULL;
		i++;
	}

	free(tokenized);
	free(rep);
	return (NULL);
}
