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

