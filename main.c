#include "main.h"

/**
 * main - entry point
 * Return: 0  on success
 */
int main(void)
{

	char *lineptr = NULL;
	size_t n = 0;
	ssize_t value;
	int isterm = isatty(0);

	while(1)
	{
		if (isterm)
			print_string("$ ");
		value = getline(&lineptr, &n, stdin);

		handle_ctrld(value, &lineptr);

		print_string(lineptr);



	}
	free(lineptr);

	return (0);
}
