#include <stdio.h>
#include <stdlib.h>

/**
 * *malloc_checked -  allocates memory using malloc.
 * @b: number of bytes to allocate
 * Return: a ptr to the allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
