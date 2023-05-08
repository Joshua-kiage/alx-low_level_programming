#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024

/**
 * main - copies content of a file to another file
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, other on failure
 */

int main(int argc, char **argv)
{
	int fd_from, fd_to, close_val;
	char buffer[BUFSIZE];
	ssize_t bytes_read, bytes_written;

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp fl_from fl_to\n"), exit(97);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from fl %s\n", argv[1]), exit(98);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

	while ((bytes_read = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	}

	if (bytes_read == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from fl %s\n", argv[1]), exit(98);

	close_val = close(fd_from);
	if (close_val == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);

	close_val = close(fd_to);
	if (close_val == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);

	return (0);
}
