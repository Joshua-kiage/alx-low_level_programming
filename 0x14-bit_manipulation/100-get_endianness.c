#include "main.h"

/**
 * get_endianness - checks the endianness
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	int num = 1;
	int *p = &num;
	char *c = (char *)p;

	return ((int)*c);
}
