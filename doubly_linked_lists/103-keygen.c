#include <stdio.h>
#include <stdlib.h>

/**
 * max_index - generates index using largest username character
 * @name: username
 * @len: username length
 *
 * Return: index
 */
int max_index(char *name, int len)
{
	int i;
	int max;
	unsigned int value;

	max = name[0];

	for (i = 0; i < len; i++)
	{
		if (name[i] > max)
			max = name[i];
	}

	srand(max ^ 14);
	value = rand();

	return (value & 63);
}

/**
 * square_index - generates index using squared characters
 * @name: username
 * @len: username length
 *
 * Return: index
 */
int square_index(char *name, int len)
{
	int i;
	int value;

	value = 0;

	for (i = 0; i < len; i++)
		value += name[i] * name[i];

	return (((unsigned int)value ^ 239) & 63);
}

/**
 * random_index - generates index using first username character
 * @name: username
 *
 * Return: index
 */
int random_index(char *name)
{
	int i;
	int value;

	value = 0;

	for (i = 0; i < name[0]; i++)
		value = rand();

	return (((unsigned int)value ^ 229) & 63);
}

/**
 * main - generates a key for crackme5
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	char key[7];
	char *table;
	long data[] = {
		0x3877445248432d41,
		0x42394530534e6c37,
		0x4d6e706762695432,
		0x74767a5835737956,
		0x2b554c59634a474f,
		0x71786636576a6d34,
		0x723161513346655a,
		0x6b756f494b646850
	};
	int len;
	int i;
	int value;

	if (argc != 2)
		return (1);

	table = (char *)data;

	for (len = 0; argv[1][len] != '\0'; len++)
		;

	key[0] = table[(len ^ 59) & 63];

	value = 0;
	for (i = 0; i < len; i++)
		value += argv[1][i];
	key[1] = table[(value ^ 79) & 63];

	value = 1;
	for (i = 0; i < len; i++)
		value *= argv[1][i];
	key[2] = table[(value ^ 85) & 63];

	key[3] = table[max_index(argv[1], len)];
	key[4] = table[square_index(argv[1], len)];
	key[5] = table[random_index(argv[1])];
	key[6] = '\0';

	printf("%s", key);

	return (0);
}
