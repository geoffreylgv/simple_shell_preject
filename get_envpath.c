#include "main.h"
/**
 * get_envpath - get the path $PATH
 * (using the old version)
 *
 * Return: char- path command
 */
char *get_envpath(void)
{
	int i;
	char *duplicate = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH", 4) == 0)
			duplicate = strdup(environ[i]);
	}
	return (duplicate);
}
