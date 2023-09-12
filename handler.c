#include "main.h"

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
 * handle_exit - function that handles the exit cmd
 * @cmd: the command value getter
 * @lineptr: the buffer
 * Return: 0 on success
 */
int handle_exit(char **cmd, char **lineptr)
{
	if (strcmp(cmd[0], "exit") == 0)
	{
		free(*lineptr);
		exit(errno);
	}
	return (0);
}
