#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - prints strings
 * @separator: string to separate the strings
 * @n: number of strings
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);

		if (str == 0)
			printf("(nil)");
		else
			printf("%s", str);

		if (separator != 0 && i < n - 1)
			printf("%s", separator);
	}

	printf("\n");
	va_end(args);
}
