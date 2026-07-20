#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * error_exit - prints an error message and exits
 * @message: error message
 * @filename: file name
 */
void error_exit(const char *message, const char *filename)
{
	if (filename != NULL)
		dprintf(STDERR_FILENO, "%s%s\n", message, filename);
	else
		dprintf(STDERR_FILENO, "%s\n", message);
	exit(98);
}

/**
 * get_16 - reads a 16-bit value with the correct byte order
 * @data: pointer to the bytes
 * @big_endian: byte order flag
 *
 * Return: the 16-bit value
 */
unsigned int get_16(unsigned char *data, int big_endian)
{
	if (big_endian)
		return (((unsigned int)data[0] << 8) | data[1]);

	return (((unsigned int)data[1] << 8) | data[0]);
}

/**
 * get_32 - reads a 32-bit value with the correct byte order
 * @data: pointer to the bytes
 * @big_endian: byte order flag
 *
 * Return: the 32-bit value
 */
unsigned long get_32(unsigned char *data, int big_endian)
{
	if (big_endian)
		return (((unsigned long)data[0] << 24) |
			((unsigned long)data[1] << 16) |
			((unsigned long)data[2] << 8) | data[3]);

	return (((unsigned long)data[3] << 24) |
		((unsigned long)data[2] << 16) |
		((unsigned long)data[1] << 8) | data[0]);
}

/**
 * get_64 - reads a 64-bit value with the correct byte order
 * @data: pointer to the bytes
 * @big_endian: byte order flag
 *
 * Return: the 64-bit value
 */
unsigned long long get_64(unsigned char *data, int big_endian)
{
	unsigned long long value;
	int i;

	value = 0;
	if (big_endian)
	{
		for (i = 0; i < 8; i++)
			value = (value << 8) | data[i];
	}
	else
	{
		for (i = 7; i >= 0; i--)
			value = (value << 8) | data[i];
	}

	return (value);
}

/**
 * print_magic - prints the ELF magic bytes
 * @header: ELF header
 */
void print_magic(unsigned char *header)
{
	int i;

	printf("  Magic:  ");
	for (i = 0; i < EI_NIDENT; i++)
		printf(" %02x", header[i]);
	printf("\n");
}

/**
 * print_class - prints the ELF class
 * @value: class value
 */
void print_class(unsigned char value)
{
	printf("  Class:                             ");

	if (value == ELFCLASS32)
		printf("ELF32\n");
	else if (value == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", value);
}

/**
 * print_data - prints the ELF data encoding
 * @value: data encoding value
 */
void print_data(unsigned char value)
{
	printf("  Data:                              ");

	if (value == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (value == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", value);
}

/**
 * print_version - prints the ELF version
 * @value: version value
 */
void print_version(unsigned char value)
{
	printf("  Version:                           %d", value);

	if (value == EV_CURRENT)
		printf(" (current)");
	printf("\n");
}

/**
 * print_osabi - prints the ELF OS/ABI
 * @value: OS/ABI value
 */
void print_osabi(unsigned char value)
{
	printf("  OS/ABI:                            ");

	switch (value)
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - GNU\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_AIX:
		printf("UNIX - AIX\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	default:
		printf("<unknown: %x>\n", value);
	}
}

/**
 * print_type - prints the ELF type
 * @type: ELF type value
 */
void print_type(unsigned int type)
{
	printf("  Type:                              ");

	switch (type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown>: %x\n", type);
	}
}

/**
 * print_entry - prints the ELF entry point address
 * @header: ELF header
 * @big_endian: byte order flag
 */
void print_entry(unsigned char *header, int big_endian)
{
	unsigned long entry32;
	unsigned long long entry64;

	printf("  Entry point address:               ");

	if (header[EI_CLASS] == ELFCLASS32)
	{
		entry32 = get_32(header + 24, big_endian);
		printf("0x%lx\n", entry32);
	}
	else
	{
		entry64 = get_64(header + 24, big_endian);
		printf("0x%llx\n", entry64);
	}
}

/**
 * validate_header - validates an ELF header
 * @header: ELF header
 * @bytes: number of bytes read
 * @filename: file name
 */
void validate_header(unsigned char *header, ssize_t bytes, char *filename)
{
	if (bytes < EI_NIDENT)
		error_exit("Error: Invalid ELF file: ", filename);

	if (header[EI_MAG0] != ELFMAG0 ||
	    header[EI_MAG1] != ELFMAG1 ||
	    header[EI_MAG2] != ELFMAG2 ||
	    header[EI_MAG3] != ELFMAG3)
		error_exit("Error: Not an ELF file: ", filename);

	if (header[EI_CLASS] == ELFCLASS32 && bytes < 52)
		error_exit("Error: Invalid ELF header: ", filename);

	if (header[EI_CLASS] == ELFCLASS64 && bytes < 64)
		error_exit("Error: Invalid ELF header: ", filename);

	if (header[EI_CLASS] != ELFCLASS32 &&
	    header[EI_CLASS] != ELFCLASS64)
		error_exit("Error: Invalid ELF class: ", filename);
}

/**
 * main - displays information from an ELF header
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	unsigned char header[64];
	ssize_t bytes;
	unsigned int type;
	int big_endian;
	int fd;

	if (argc != 2)
		error_exit("Usage: elf_header elf_filename", NULL);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Can't open file ", argv[1]);

	bytes = read(fd, header, sizeof(header));
	if (bytes == -1)
		error_exit("Error: Can't read file ", argv[1]);

	if (close(fd) == -1)
		error_exit("Error: Can't close file ", argv[1]);

	validate_header(header, bytes, argv[1]);
	big_endian = header[EI_DATA] == ELFDATA2MSB;
	type = get_16(header + 16, big_endian);

	printf("ELF Header:\n");
	print_magic(header);
	print_class(header[EI_CLASS]);
	print_data(header[EI_DATA]);
	print_version(header[EI_VERSION]);
	print_osabi(header[EI_OSABI]);
	printf("  ABI Version:                       %d\n",
	       header[EI_ABIVERSION]);
	print_type(type);
	print_entry(header, big_endian);

	return (0);
}
