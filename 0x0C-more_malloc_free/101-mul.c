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
 * @num1: the first integer
 * @num2: the second integer
 *
 * Return: the result of multiplying num1 and num2
 */

int multiply(int num1, int num2)
{
	return (num1 * num2);
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
	int num1;
	int num2;
	int result;

	if (argc != 3)
	{
		print_error();
	}
	num1 = parse_int(argv[1]);
	num2 = parse_int(argv[2]);
	result = multiply(num1, num2);

	printf("%d\n", result);
	return (0);
}
