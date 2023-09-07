#include "main.h"

/**
 * main - entry point
 * Return: 0  on success
 */
int main(void)
{

	char *lineptr;
	size_t n = 0;

	while(1)
	{
		print_string("oursimpleshell$ ");
		getline(&lineptr, &n, stdin);

	}

	return (0);
}
