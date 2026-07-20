#include "main.h"

/**
 * palindrome_len - returns the length of a string
 * @s: string
 *
 * Return: length
 */
int palindrome_len(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + palindrome_len(s + 1));
}

/**
 * palindrome_check - checks if a string is a palindrome
 * @s: string
 * @start: first index
 * @end: last index
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int palindrome_check(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (palindrome_check(s, start + 1, end - 1));
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	return (palindrome_check(s, 0, palindrome_len(s) - 1));
}
