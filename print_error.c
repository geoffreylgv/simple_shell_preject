#include "main.h"

/**
 * print_error - prints the corresponding
 * error to the user
 * @run: number of time the program was run
 * @cmd: the command entered by the user
 * @msg: the error message
 *
 * Return: n/a void
 */
void print_error(char run, char *cmd, char *msg)
{
	print_string2("./hsh: ");
	_putchar2(run);
	print_string2(": ");
	print_string2(cmd);
	print_string2(": ");
	print_string2(msg);
	print_string2("\n");
}

