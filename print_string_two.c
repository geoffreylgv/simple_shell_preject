#include "main.h"

/**
 * _putchar2 - prints out a character
 * @c: first char param
 *
 * Return: 1 on success, -1 on fail
 */
int _putchar2(char c)
{
	return (write(2, &c, 1));
}

/**
 * _puts2 - prints string
 * @c: char to print
 * Return: n/a void
 */
void _puts2(char *str)
{
	while (*str != '\0')
	{
		_putchar2(*str);
		str++;
	}
}

/**
 * print_string2 - prints out the string passed
 * @str: the string param
 * Return: integer number of character printed
 */
int print_string2(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		i = print_string2("(null)");
		return (i);
	}

	while(*str != '\0')
	{
		_putchar2(*str);
		str++;
		i++;
	}
	return (i);
}
