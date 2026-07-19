#include "main.h"
#include <stdlib.h>

/**
 * _putchar - writes a character
 * @c: character
 *
 * Return: character written
 */
int _putchar(char c);

/**
 * print_error - prints Error and exits
 */
void print_error(void)
{
	char *e = "Error\n";
	int i;

	for (i = 0; e[i]; i++)
		_putchar(e[i]);
	exit(98);
}

/**
 * is_digit - checks digits
 * @s: string
 *
 * Return: 1 if digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i;

	if (!s[0])
		return (0);

	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _strlen - string length
 * @s: string
 *
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int len1, len2, len, i, j, n1, n2, carry;
	int *res;

	if (argc != 3)
		print_error();

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();

	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	len = len1 + len2;

	res = malloc(sizeof(int) * len);
	if (!res)
		return (1);

	for (i = 0; i < len; i++)
		res[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = argv[1][i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = argv[2][j] - '0';
			carry += res[i + j + 1] + (n1 * n2);
			res[i + j + 1] = carry % 10;
			carry /= 10;
		}
		res[i] += carry;
	}

	i = 0;
	while (i < len - 1 && res[i] == 0)
		i++;

	while (i < len)
		_putchar(res[i++] + '0');

	_putchar('\n');
	free(res);

	return (0);
}
