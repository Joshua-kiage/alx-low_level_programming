#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: void
 */

void print_all(const char * const format, ...)
{
	va_list args;
	char *str;
	unsigned int i = 0, j;
	char format_specifier;
	const char *separator = "";

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;
		format_specifier = format[i];

		switch (format_specifier)
		{
			case 'c':
				printf("%s%c", separator, va_arg(args, int));
				break;
			case 'i':
				printf("%s%d", separator, va_arg(args, int));
				break;
			case 'f':
				printf("%s%f", separator, va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s%s", separator, str);
				break;
			default:
				j = 1;
				break;
		}
		if (j == 0)
			separator = ", ";
		i++;
	}
	printf("\n");
	va_end(args);
}
