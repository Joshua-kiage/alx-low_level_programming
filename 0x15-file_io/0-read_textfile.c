#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 * Return: actual number of letters read and printed,or 0 if an error occurred
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t num_read, num_write;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);

	if (buf == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	num_read = read(fd, buf, letters);
	num_write = write(STDOUT_FILENO, buf, num_read);

	if (fd == -1 || num_read == -1 || num_write == -1 || num_write != num_read)
		return (0);

	close(fd);

	free(buf);

	return (num_write);
}
