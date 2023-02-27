#include "main.h"

/**
 * print_rev - prints str in reverse, followed by a new line
 * @s: ptr to the string to print
 * Return: void
 */

void print_rev(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	while (i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
