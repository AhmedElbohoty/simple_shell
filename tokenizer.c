#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"

/**
 * tokenizer - splits a string
 * @str: pointer to the string
 *
 * Return: Null-terminated array of strings
 */
char **tokenizer(char *str)
{
	char *delim = " \n"; /* \n - used to remove newline at the end of command*/
	char **tokens = NULL;

	tokens = words_list(str, delim);

	return (tokens);
}

/**
 * words_list - Get Null-terminated array of words
 * @str: pointer to the string
 * @delim: pointer to delimiter
 *
 * Return: pointer to Null-terminated array of strings
 */
char **words_list(char *str, char *delim)
{
	char **argv = NULL;
	size_t str_size = strlen(str);
	size_t arr_size = tokens_count(str, delim);
	char prev_char = '\0';
	size_t i = 0;
	int j = 0;

	argv = malloc(sizeof(char *) * (arr_size + 1));

	for (i = 0; i < str_size; i++)
	{
		if (str[i] == ' ')
		{
			prev_char = str[i];
			continue;
		}

		if (str[i] != '\0' && (prev_char == '\0' || prev_char == ' '))
		{
			argv[j] = &str[i];
			j++;
		}
		prev_char = str[i];
	}
	argv[j] = NULL;

	return (argv);
}

/**
 * tokens_count - Get the count of tokens
 * @str: pointer to the string
 * @delim: pointer to delimiter
 *
 * Return: count of tokens
 */
size_t tokens_count(char *str, char *delim)
{
	size_t count = 0;

	if (strtok(str, delim) != NULL)
		count++;

	while (strtok(NULL, delim))
		count++;

	return (count);
}
