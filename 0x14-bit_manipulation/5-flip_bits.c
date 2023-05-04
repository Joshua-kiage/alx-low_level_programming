#include "main.h"

/**
 * flip_bits - returns the number of bits needed to flip to get from n to m
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int bits = 0;
	unsigned long int xor = n ^ m;

	while (xor > 0)
	{
		if (xor & 1)
			bits++;
		xor >>= 1;
	}

	return (bits);
}
