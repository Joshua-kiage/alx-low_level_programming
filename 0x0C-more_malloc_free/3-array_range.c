#include <stdlib.h>
#include "main.h"

/**
 * *array_range -  creates an array of integers.
 * @min: minum value
 * @max: maximum value
 * Return: pointer to the newly created array
 * If min > max, return NULL
 * If malloc fails, return NULL
 */

int *array_range(int min, int max)
{
	int *arr;
	int n;
	int i;

	if (min > max)
		return (NULL);

	n = max - min + 1;

	arr = malloc(n * sizeof(arr));

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
		arr[i] = min + i;

	return (arr);
}
