#include "main.h"
#include <string.h>

/**
 * create_file - creates a file with the given name
 *               and writes the given text to it
 * @filename: the name of the file to create
 * @text_content: a NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	FILE *fp;
	int ret = -1;

	if (filename == NULL)
		return (-1);

	fp = fopen(filename, "w");
	if (fp == NULL)
		return (-1);

	if (text_content != NULL)
	{
		size_t len = strlen(text_content);

		if (fwrite(text_content, sizeof(char), len, fp) == len)
			ret = 1;
	}
	else
		ret = 1;

	fclose(fp);

	return (ret);
}
