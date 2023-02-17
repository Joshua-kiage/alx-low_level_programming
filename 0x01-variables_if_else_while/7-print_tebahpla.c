#include <stdio.h>

/**
 * main -  program that prints the lowercase alphabet in reverse
 * Return: Always 0 (success)
 */
int main(void)
{
	char lf;

	for (lf = 'z'; lf >= 'a'; lf--)
		putchar(lf);

	putchar('\n');

	return (0);
}
