#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints arguments according to a format
 * @format: list of argument types
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i;
	char *str;
	char *separator;

	i = 0;
	separator = "";
	va_start(args, format);

	while (format != 0 && format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", separator, va_arg(args, int));
			separator = ", ";
			break;
		case 'i':
			printf("%s%d", separator, va_arg(args, int));
			separator = ", ";
			break;
		case 'f':
			printf("%s%f", separator, va_arg(args, double));
			separator = ", ";
			break;
		case 's':
			str = va_arg(args, char *);
			if (str == 0)
				str = "(nil)";
			printf("%s%s", separator, str);
			separator = ", ";
			break;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}
