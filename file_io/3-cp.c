#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * close_file - closes a file descriptor
 * @fd: file descriptor
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * read_error - handles a read error
 * @filename: source file name
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 */
void read_error(char *filename, int fd_from, int fd_to)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	close_file(fd_from);
	close_file(fd_to);
	exit(98);
}

/**
 * write_error - handles a write error
 * @filename: destination file name
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 */
void write_error(char *filename, int fd_from, int fd_to)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	close_file(fd_from);
	close_file(fd_to);
	exit(99);
}

/**
 * copy_file - copies content between file descriptors
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @from: source file name
 * @to: destination file name
 */
void copy_file(int fd_from, int fd_to, char *from, char *to)
{
	char buffer[1024];
	ssize_t bytes_read;
	ssize_t bytes_written;

	while ((bytes_read = read(fd_from, buffer, 1024)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
			write_error(to, fd_from, fd_to);
	}

	if (bytes_read == -1)
		read_error(from, fd_from, fd_to);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from;
	int fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_file(fd_from);
		exit(99);
	}

	copy_file(fd_from, fd_to, argv[1], argv[2]);
	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
