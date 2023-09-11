#include "main.h"

/**
 * main - entry point
 * Return: 0  on success
 */
int main(int argc, char **argv, char **env)
{

	char *lineptr = NULL, **args = NULL, *get_cmd = NULL;
	size_t n = 0;
	ssize_t value;
	int isterm = isatty(0), iter = 0;

	(void)argc,(void)env, argv = NULL;

	while(1)
	{
		iter++;
		if (isterm == 1)
			print_string("$ ");
		value = getline(&lineptr, &n, stdin);

		if (value == -1)
			handle_ctrld(value, &lineptr);
		/** tokenization*/
		args = token_string(lineptr);
		if (args[0] == NULL)
		{
			free(args);
			continue;
		}
		/** access right on the path*/
		if (access(args[0], X_OK) == -1)
		{
			get_cmd = path(get_envpath(), args[0]);

			if (get_cmd == NULL)
			{
				print_error((iter + '0'), args[0], "not found");
				free(args);
				errno = 127;
				continue;
			}
			launch_one(args, argv, get_cmd);
			continue;
		}
		launch_two(args, argv);
		continue;


	}
	free(lineptr);

	return (0);
}
