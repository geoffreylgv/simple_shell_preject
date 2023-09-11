#include "main.h"

/**
 * _putchar - prints out a character
 * @c: first char param
 *
 * Return: 1 on success, -1 on fail
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints string
 * @c: char to print
 * Return: n/a void
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}

/**
 * print_strin - prints out the string passed
 * @str: the string param
 * Return: integer number of character printed
 */
int print_string(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		i = print_string("(null)");
		return (i);
	}

	while(*str != '\0')
	{
		_putchar(*str);
		str++;
		i++;
	}
	return (i);
}
