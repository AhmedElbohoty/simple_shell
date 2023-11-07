#include <string.h>

/**
 * replace_char - replace character at string with another character
 * @str: Pointer to the string
 * @c1: character to be replaced
 * @c2: the second character
 *
 * Return: Nothing
 */
void replace_char(char *str, char c1, char c2)
{
	int i;
	int len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] == c1)
			str[i] = c2;
	}
}

/**
 * _strlen - returns the length of a string
 * @s: pointer to string
 *
 * Return: the length of a string
 */
int _strlen(char *s)
{
	int len = 0;

	if (*s == '\0')
		return (len);

	len = 1 + _strlen(s + 1);

	return (len);
}

/**
 * _strcmp -  compares two strings
 * @s1: the first pointer to string
 * @s2: the second pointer to string
 *
 * Return: 0 if two strings equal
 *         +ve if s1 > s2
 *         -ve if s1 < s2
 */

int _strcmp(char *s1, char *s2)
{
	int res = 0;

	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			break;

		s1++;
		s2++;
	}

	res = *s1 - *s2;

	return (res);
}

/**
 * *_strchr - locates a character in a string.
 * @s: the pointer to string
 * @c: the character
 *
 * Return: a pointer to the first occurrence of the character c in the
 *         string s, or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	char *pt = 0;

	while (*s != '\0')
	{
		if (*s == c)
			break;
		s++;
	}

	if (*s != c)
		return (pt);

	return (s);
}
