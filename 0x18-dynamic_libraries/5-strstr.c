#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: input
 * @needle: input
 * Return: Always 0 (success)
 */

char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *k = haystack;
		char *l = needle;

		while (*k == *l && *l != '\0')
		{
			k++;
			l++;
		}
		if (*l == '\0')
			return (haystack);
	}
	return (0);
}
