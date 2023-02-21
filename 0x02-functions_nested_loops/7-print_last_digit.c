#include "main.h"

/**
 * print_last_digit - prints the last digit
 * @n: the number
 * Return: value of the last digit
 */
int print_last_digit(int n)
{
	int ld = n % 10;

	if (ld < 0)
		ld = ld < 0 ? -1 * ld : ld;

	_putchar(ld + 'o');

	return (ld < 0 ? -1 * ld : ld);
}
