#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string
 *
 * Return: pointer to string
 */
char *cap_string(char *str)
{
	int i = 0;
	int j;
	char sep[] = " \t\n,;.!?\"(){}";

	while (str[i] != '\0')
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;

		for (j = 0; sep[j] != '\0'; j++)
		{
			if (str[i] == sep[j] &&
			    str[i + 1] >= 'a' &&
			    str[i + 1] <= 'z')
				str[i + 1] -= 32;
		}
		i++;
	}

	return (str);
}
