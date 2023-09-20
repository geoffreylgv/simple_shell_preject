
#include "main.h"

/**
 * check_and_launch_file - Function	to check if the	file exists
 * and is executable and launch	it if it is. Otherwise,
 * print an error message.
 * @args: command cahr pointer
 * @isterm: if it's a tty (isatty)
 * @iter: command run count
 * Return: errno (last status)	on success or not
 */
void check_and_launch_file(char	**args, char **argv, int isterm, int iter)	{

	char *get_cmd = path(get_envpath(), args[0]);

	if (get_cmd == NULL)
	{
		print_error((iter + '0'), args[0], "not	found");
		if (isterm != 1)
			exit(127);

		errno =	127;
		return;
  	}

	launch_one(args, argv, get_cmd);
}

/**
 * main	- entry	point
 * @argv: array	with size of argc
 * @argc: the size of argv
 * @env: environment path
 * Return: errno (last status)	on success or not
 */
int main(int argc, char **argv, char **env)
{

	char *lineptr = NULL, **args = NULL;
  	size_t n = 0;
	ssize_t value;
	int isterm = isatty(0), iter = 0;
	errno = 0;

	(void)argc, (void)env, argv = NULL;

	while (1)
	{
		iter++;
		if (isterm == 1)
			print_string("$ ");

		value =	getline(&lineptr, &n, stdin);

		if (value == -1)
			handle_ctrld(value, &lineptr);

		args = token_string(lineptr);

		if (args[0] == NULL)
		{
			free(args);
			continue;
		}
		if (access(args[0], X_OK) == -1)
		{
			if (builtin_handler(args, lineptr) != 0)
				continue;

			check_and_launch_file(args, argv, isterm, iter);
				continue;
		}
		launch_two(args, argv);
			continue;
	}
	free(lineptr);
	return (errno);
}

