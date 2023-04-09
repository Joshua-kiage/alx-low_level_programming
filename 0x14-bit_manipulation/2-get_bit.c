#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: the number to get the bit from
 * @index: the index of the bit to get, starting from 0
 * Return: the value of the bit at index,
 *         index or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i = index;

	if (index >= (sizeof(n) * 8))
		return (-1);

	for (index = 0; index < 64; index++)
	{
		if (i == index)
			return ((n >> i) & 1);
	}
	return (-1);
}
