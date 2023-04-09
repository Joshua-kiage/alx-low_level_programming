#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: Pointer to a string of 0 and 1 chars
 *
 * Return: The converted number, or 0 if there is one or more chars
 * in the string b that is not 0 or 1 or if b is NULL.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int ui = 0;

	if (!b)
		return (0);

	while (*b)
	{
		if (*b != '1' && *b != '0')
			return (0);

		ui <<= 1;
		if (*b == '1')
			ui += 1;
		b++;
	}

	return (ui);
}
