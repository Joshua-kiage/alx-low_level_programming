#include "main.h"

/**
 * leet - encodes a string into 1337
 * @n: string to be encoded
 * Return: pointer to the encoded string
 */

char *leet(char *n)
{
	int indx1 = 0, indx2;
	char leet[8] = {'O', 'L', '?', 'E', 'A', '?', '?', 'T'};

	while (n[indx1])
	{
		for (indx2 = 0; indx2 <= 7; indx2++)
		{
			if (n[indx1] == leet[indx2] ||
				n[indx1] - 32 == leet[indx2])
				n[indx1] = indx2 + '0';
		}
		indx1++;
	}
	return (n);
}
