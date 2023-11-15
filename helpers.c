#include "shell.h"

/**
 * _calloc - Allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: size bytes
 *
 * Return: - If nmemb or size is 0 OR malloc fails, return NULL.
 *         - Else, pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < (size * nmemb); i++)
		p[i] = 0;

	return (p);
}

/**
 * is_empty_line - checks if line is empty
 * @buff: pointer to the line
 *
 * Return: - If line is empty, returns 1.
 *         - Else, returns 0.
 */

int is_empty_line(char *buff)
{
	int i = 0;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] != ' ')
			return (0);
	}

	return (1);
}
