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
	size_t len;

	if (filename == NULL || text_content == NULL)
	{
		errno = EINVAL;
		return (-1);
	}

	len = strlen(text_content);
	
	fp = fopen(filename, "w");

	if (fp == NULL)
	{
		perror("Error opening file");
		return (-1);
	}

	if (fwrite(text_content, sizeof(char), len, fp) != len)
	{
		perror("Error writing to file");
		fclose(fp);
		return (-1);
	}
	fclose(fp);
	return (0);
}
