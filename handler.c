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
		exit(0);
	}
}
