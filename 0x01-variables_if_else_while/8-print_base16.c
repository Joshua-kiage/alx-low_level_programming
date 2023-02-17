#include <stdio.h>

/**
 * main - program that prints all the numbers of base 16 in lowercase
 * Return: Always 0 (success)
 */
int main(void)
{
	int num;
	char ld;

	for (num = 0; num < 10; num++)
		putchar((num % 10) + '0');

	for (ld = 'a'; ld <= 'f'; ld++)
		putchar(ld);

	putchar('\n');

	return (0);
}
