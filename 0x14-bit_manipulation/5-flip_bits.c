#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip
 *             to get from one number to another.
 * @n: 1st number
 * @m: 2nd number
 * Return: number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int num_bits = 0;

	while (n != 0 || m != 0)
	{
		if ((n & 1) != (m & 1))
			num_bits++;

		n >>= 1;
		m >>= 1;
	}

	return (num_bits);
}
