#include <stdio.h>

/**
 * main - prints the largest prime factor
 *
 * Return: Always 0
 */
int main(void)
{
	long number;
	long factor;

	number = 612852475143;
	factor = 2;

	while (factor * factor <= number)
	{
		if (number % factor == 0)
		{
			number = number / factor;
		}
		else
		{
			factor++;
		}
	}

	printf("%ld\n", number);

	return (0);
}
