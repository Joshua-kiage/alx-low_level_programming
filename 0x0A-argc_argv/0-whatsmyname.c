#include "main.h"
#include <stdio.h>

/**
 * main - prints its name, followed by a new line
 * @argc: count arguments
 * @argv: arguments
 *
 * Return: Always 0 (success)
 */

int main(int argc, char *argv[])
{

	(void) argv; /*Ignore argv*/

	printf("%d\n", argc - 1);

	return (0);
}
