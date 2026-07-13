#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a valid password for 101-crackme
 *
 * Return: Always 0
 */
int main(void)
{
	int sum;
	int value;

	sum = 0;
	srand(time(NULL));

	while (sum < 2772 - 126)
	{
		value = (rand() % 94) + 33;
		putchar(value);
		sum += value;
	}

	putchar(2772 - sum);
	putchar('\n');

	return (0);
}
