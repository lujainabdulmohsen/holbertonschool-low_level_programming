#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	int n;
	int *p;

	n = 402;
	p = &n;
	((char *)p)[5] = 98;
	printf("a[2] = %d\n", n);
	return (0);
}
