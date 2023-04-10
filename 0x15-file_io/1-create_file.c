#include "main.h"

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
	int ret;

	if (filename == NULL)
		return (-1);

	fp = fopen(filename, "w");
	if (fp == NULL)
		return (-1);

	ret = (text_content == NULL) ? 0 : fprintf(fp, "%s", text_content);

	fclose(fp);

	return (ret < 0 ? -1 : 1);
}
