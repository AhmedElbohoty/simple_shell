#include "shell.h"

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
 * Return: - If two strings equal, return 0.
 *         - If s1 > s2, return +ve.
 *         - If s1 < s2, return -ve.
 */
int _strcmp(char *s1, char *s2)
{
	int res = 0;

	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			res = 0;
			break;
		}
		s1++;
		s2++;
	}

	res = *s1 - *s2;

	return (res);
}

/**
 * *_strcpy - prints n elements of an array of integers,
 *               followed by a new line
 * @dest: the first pointer to copy
 * @src: the second pointer to array
 *
 * Return: Nothing.
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (ptr);
}

/**
 * str_concat - concatenates two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: - If success, returns pointer.
 *         - Else, returns NULL
 */
char *str_concat(char *s1, char *s2)
{
	int i, j, s1_len, s2_len;
	char *p;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	s1_len = _strlen(s1);
	s2_len = _strlen(s2);

	/* Add one byte for null terminated */
	p = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));

	if (p == NULL)
		return (NULL);

	for (i = 0; i < s1_len; i++)
		p[i] = s1[i];

	for (j = 0; j < s2_len; j++)
	{
		p[i] = s2[j];
		i++;
	}
	p[i] = '\0';

	return (p);
}

/**
 * _split - split string
 * @str: pointer to string
 * @sep: pointer to separator
 *
 * Return: splitted strings
 */
char **_split(char *str, char *sep)
{
	int i = 0;
	char *temp;
	char **res;

	temp = strtok(str, sep);

	res = (char **)_calloc(100, sizeof(char *));

	if (!res)
	{
		free(res);
		return (NULL);
	}

	while (temp)
	{
		res[i] = temp;
		temp = strtok(NULL, sep);
		i++;
	}

	return (res);
}

