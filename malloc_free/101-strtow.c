#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts words in a string
 * @str: string to check
 *
 * Return: number of words
 */
int count_words(char *str)
{
	int i, count;

	i = 0;
	count = 0;
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
 * free_words - frees an array of words
 * @words: array to free
 * @count: number of allocated words
 */
void free_words(char **words, int count)
{
	while (count > 0)
	{
		count--;
		free(words[count]);
	}
	free(words);
}

/**
 * word_length - finds the length of a word
 * @str: string containing the word
 *
 * Return: length of the word
 */
int word_length(char *str)
{
	int len;

	len = 0;
	while (str[len] && str[len] != ' ')
		len++;
	return (len);
}

/**
 * copy_word - copies a word into allocated memory
 * @str: source string
 * @len: length of the word
 *
 * Return: pointer to the copied word
 */
char *copy_word(char *str, int len)
{
	char *word;
	int i;

	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		word[i] = str[i];
	word[i] = '\0';
	return (word);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: array of words, or NULL
 */
char **strtow(char *str)
{
	char **words;
	int i, count, len, word;

	if (str == NULL || *str == '\0')
		return (NULL);
	count = count_words(str);
	if (count == 0)
		return (NULL);
	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);
	i = 0;
	word = 0;
	while (word < count)
	{
		while (str[i] == ' ')
			i++;
		len = word_length(str + i);
		words[word] = copy_word(str + i, len);
		if (words[word] == NULL)
		{
			free_words(words, word);
			return (NULL);
		}
		i += len;
		word++;
	}
	words[word] = NULL;
	return (words);
}
