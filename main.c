#include "main.h"

/**
 * main - entry point
 * Return: 0  on success
 */
int main(int argc, char **argv, char **env)
{

	char *lineptr = NULL/*, **tokens = NULL*/, *sep = " \n";
	size_t n = 0;
	ssize_t value;
	int isterm = isatty(0), i = 0, j = 0, iter = 0, status;
	pid_t child;
	int run;

	(void)argc, (void)argv;

	while(1)
	{
		iter++;
		if (isterm == 1)
			print_string("$ ");
		value = getline(&lineptr, &n, stdin);

		if (value == -1)
			handle_ctrld(value, &lineptr);

		while (lineptr[i])
		{
			if (lineptr[i] == '\n')
				lineptr[i] = 0;
			i++;
		}
		argv[j] = strtok(lineptr, sep);
		child = fork();
		while (argv[j])
			argv[++j] = strtok(NULL, sep);

		if (child == - 1)
		{
			perror("");
			exit(0);
		}
		else if (child == 0)
		{
			run = execve(lineptr, argv, env);
			if (run == -1)
				perror("hsh :iter :lineptr :command not found");
		}
		else
		{
			wait(&status);
			errno = WIFEXITED(status);
		}


	}
	free(lineptr);

	return (0);
}
