#include "main.h"

/**
 * launch_two - Launch 2 command
 * @args: command array
 * @argv: array of command
 * Return: int state
 */

int launch_two(char **args, char **argv)
{
	pid_t pid;
	int state;

	pid = fork();
	if (pid < 0)
	{
		perror(argv[0]);
		exit(-1);
	}
	else if (pid == 0)
	{
		execve(args[0], args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&state);
		if (WIFEXITED(state))
			state = WEXITSTATUS(state);

		errno = state;

		free(args);
	}

	return (state);
}
