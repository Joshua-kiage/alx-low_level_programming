#include <stdio.h>
#include <stdlib.h>

/**
 * *malloc_checked -  allocates memory using malloc.
 * @b: number of bytes to allocate
 * Return: a ptr to the allocated memory
 * if malloc fails, status value is equal to EXIT_FAILURE
 */

void *malloc_checked(unsigned int b)
{
	char *ptr;

	*ptr = malloc(b);
	if (ptr == NULL)
		exit(EXIT_FAILURE);
	return (ptr);
}
