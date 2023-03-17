#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * print_error - prints an error message
 * and terminates the program
 *
 * Return: does not return a value
 */

void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * parse_int - converts a string to an integer
 *
 * @str: pointer to the string to be converted
 *
 * Return: the integer value of the string
 *         exits program with status code 98 if the string contains
 *         non-digit characters
 */

int parse_int(char *str)
{
	int result = 0;

	while (*str)
	{
		if (!isdigit(*str))
		{
			print_error();
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

/**
 * multiply - multiplies two integers
 *
 * @a: first num
 * @b: second num
 *
 * Return: result of multiplication
 */

int multiply(int a, int b)
{
	return (a * b);
}

/**
 * main - entry point for the program
 *
 * @argc: number of arguments passed to the program
 * @argv: array of strings containing the arguments
 *
 * Return: 0 on success, exits program with status code 98 if the wrong
 *         number of arguments is provided
 */

int main(int argc, char **argv)
{
	int a;
	int b;
	int result;

	if (argc != 3)
	{
		print_error();
	}
	a = parse_int(argv[1]);
	b = parse_int(argv[2]);
	result = mul(a, b);

	printf("%d\n", result);
	return (0);
}
