#include <stdio.h>
#include "shell.h"

/**
 * _atoi -  convert a string to an integer
 * @s: the first pointer to string
 *
 * Return: Number if there is number
 *         else 0
 */
int _atoi(char *s)
{
	int i = 0;
	int si = 1;
	int res = 0;

	/* Iterate through all characters */
	while (s[i] != '\0')
	{
		/* Update the sign of digit */
		if (s[i] == '-')
			si *= -1;

		if (!_isdigit(s[i]))
		{
			i++;
			continue;
		}

		while (_isdigit(s[i]))
		{
			/* Subtract the code from '0' to get numerical value. */
			/* Multiply res by 10 to shuffle digits left. */
			res = (s[i] - '0') * si + res * 10;
			i++;
		}
		break;

		i++;
	}
	return (res);
}

/**
 * _isdigit - checks for a digit (0 through 9).
 * @n: the char to be checked
 *
 * Return: Always 0.
 */
int _isdigit(int n)
{
	return (n >= '0' && n <= '9');
}

