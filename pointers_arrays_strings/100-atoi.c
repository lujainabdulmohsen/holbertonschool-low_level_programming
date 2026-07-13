#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: string
 *
 * Return: integer converted from the string
 */
int _atoi(char *s)
{
	int i;
	int sign;
	unsigned int num;

	i = 0;
	sign = 1;
	num = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			while (s[i] >= '0' && s[i] <= '9')
			{
				num = (num * 10) + (s[i] - '0');
				i++;
			}
			return (num * sign);
		}
		i++;
	}

	return (0);
}
