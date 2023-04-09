#include "main.h"

/**
 * read_textfile - reads a text file and prints
 *                 it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 * Return: actual number of letters read and printed,
 *         or 0 if an error occurred
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char buf[BUFSIZ];
	ssize_t total_read = 0, num_read, num_written;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	while (letters > 0 && (num_read = read(fd, buf, BUFSIZ)) > 0)
	{
		num_written = write(STDOUT_FILENO, buf, num_read);

		if (num_written == -1)
		{
			close(fd);
			return (0);
		}

		total_read += num_written;
		letters -= num_written;
	}

	close(fd);
	return (total_read);
}
