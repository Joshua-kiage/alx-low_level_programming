#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: the number to search
 * @index: the index of the bit to retrieve, starting from 0
 *
 * Return: the value of the bit at index index or -1 if an error occurred
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int value;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	value = (n & (1 << index)) >> index;

	return (value);
}
