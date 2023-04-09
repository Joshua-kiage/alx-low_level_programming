#include "main.h"

/**
 * read_textfile - reads a text file and prints it
 *                 to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 * Return: actual number of letters read and printed,
 *         or 0 if an error occurred
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t num_read, num_write;
	char *buf;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	num_read = read(fd, buf, letters);
	num_write = write(STDOUT_FILENO, buf, num_read);

	close(fd);

	free(buf);

	return (num_write);
}
