#include "main.h"

/**
 * launch_one - Lanch 1 command
 * @args: commands array
 * @argv: array command
 * @getcmd: getcommand user typed
 * Return: int state
 */

int launch_one(char **args, char **argv, char *getcmd)
{
	int state;
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror(getcmd);
		exit(-1);
	}
	else if (pid == 0)
	{
		execve(getcmd, args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&state);
		if (WIFEXITED(state))
			state = WEXITSTATUS(state);
		errno = state;

		free(getcmd);
		free(args);
	}
	return (state);
}
