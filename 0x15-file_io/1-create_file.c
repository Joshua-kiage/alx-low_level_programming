#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * create_file - creates a file with specified content
 * @filename: the name of the file to create
 * @text_content: the content to write to the file (NULL to create empty file)
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd, text_len, ret_val;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (text_len = 0; text_content[text_len]; text_len++)
			;
		ret_val = write(fd, text_content, text_len);

		if (ret_val == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
