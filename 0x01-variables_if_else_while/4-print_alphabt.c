#include <stdio.h>

/**
 * main -  program that prints the alphabet in lowercase
 * followed by a new line,except q and e
 * Return: Always 0 (success)
 */
int main(void)
{
	char la;

	for (la = 'a'; la <= 'z'; la++)

		if (la != 'q' && la != 'e')
			putchar(la);
	putchar('\n');

	return (0);
}
