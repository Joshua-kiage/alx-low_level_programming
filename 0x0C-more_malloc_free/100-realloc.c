#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * with a call to malloc: malloc(old_size)
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes of the new memory block
 * Return: ptr
 * If new_size > old_size, the “added” memory should not be initialized
 * If new_size == old_size do not do anything and return ptr
 * If ptr is NULL, then the call is equivalent to malloc(new_size)
 * for all values of old_size and new_size
 * If new_size is equal to zero, and ptr is not NULL
 * then the call is equivalent to free(ptr). Return NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (ptr == NULL)
		ptr = (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	free(ptr);
	ptr = malloc(new_size);

	if (new_size == 0 && ptr !=  NULL)
	{
		return (NULL);
		free(ptr);
	}

	return (ptr);
}
