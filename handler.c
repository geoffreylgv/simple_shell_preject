#include "main.h"

/**
 * _strlen - count chars
 * @s: data from user
 * Return: The result
 */
int _strlen(char *s)
{
	int i = 0, length = 0;

	while (s[i++])
		length++;
	return (length);
}

/**
 * handle_ctrld - function that handles the ctrl d
 * @value: the value of getine
 * @lineptr: the buffer
 * Return: NA
 */
void handle_ctrld(ssize_t value, char **lineptr)
{
	if (value == -1)
	{
		free(*lineptr);
		exit(errno);
	}
}

/**
 * builtin_handler - function that handles the exit cmd
 * @cmd: the command value getter
 * @lineptr: the buffer
 * Return: 0 on success
 */
int builtin_handler(char **cmd, char *lineptr)
{
	int success = 0, i;

	if (strcmp(cmd[0], "exit") == 0)
	{
		free(cmd);
		free(lineptr);
		exit(errno);
	}
	else if (strcmp(cmd[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			print_string(environ[i]);
			_putchar('\n');
		}
		/*free(*cmd);*/
		success = 1;
	}

	return (success);
}

/**
 * handle_htag - Funtion that Checks if the string start by htag
 * if string is comment
 * @strtag: check string given and fix htag by \0
 * Return: NA nothing
 */

void handle_htag(char *strtag)
{
	int i = 0;

	while (strtag[i])
	{
		if (i > 0 && strtag[i] == '#' && strtag[i - 1] != ' ')
			break;

		if (strtag[i] == '#')
		{
			strtag[i] = '\0';
			break;
		}
		i++;
	}
}

