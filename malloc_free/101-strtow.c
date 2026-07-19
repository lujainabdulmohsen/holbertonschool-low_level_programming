#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts the number of words
 * @str: input string
 *
 * Return: number of words
 */
int count_words(char *str)
{
	int i, count;

	count = 0;
	i = 0;

	while (str[i])
	{
		while (str[i] == ' ')
			i++;

		if (str[i])
		{
			count++;

			while (str[i] && str[i] != ' ')
				i++;
		}
	}

	return (count);
}

/**
 * free_words - frees allocated memory
 * @words: array of words
 * @n: number of allocated words
 */
void free_words(char **words, int n)
{
	while (n--)
		free(words[n]);

	free(words);
}

/**
 * strtow - splits a string into words
 * @str: input string
 *
 * Return: array of words, or NULL
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, start, len, count;

	if (str == NULL || *str == '\0')
		return (NULL);

	count = count_words(str);
	if (count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);

	i = 0;
	k = 0;
	while (k < count)
	{
		while (str[i] == ' ')
			i++;

		start = i;
		len = 0;

		while (str[i] && str[i] != ' ')
		{
			len++;
			i++;
		}

		words[k] = malloc(sizeof(char) * (len + 1));
		if (words[k] == NULL)
		{
			free_words(words, k);
			return (NULL);
		}

		for (j = 0; j < len; j++)
			words[k][j] = str[start + j];

		words[k][j] = '\0';
		k++;
	}

	words[k] = NULL;

	return (words);
}
