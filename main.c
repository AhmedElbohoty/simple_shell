#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - prints the environment
 * @ac: The args count.
 * @av: The args vector.
 * @env: The environment vectors.
 *
 * Return: Always 0 (Success).
 */
int main(__attribute__((unused)) int ac, char **av,
		 __attribute__((unused)) char **env)
{
	char *buff = NULL, *prompt_symbol = "($) ";
	int non_term = 0;
	size_t buff_size = 0;
	ssize_t line = 0;

	while (1 && !non_term)
	{
		if (isatty(STDIN_FILENO) == 0)
			non_term = 1;

		if (!non_term)
			print(prompt_symbol);

		line = getline(&buff, &buff_size, stdin);
		if (line == -1)
		{
			free(buff);
			print_error(av[0]);
			exit(EXIT_FAILURE);
		}

		if (buff[0] == '\n')
			continue;

		buff[_strlen(buff) - 1] = '\0';
	}

	free(buff);

	exit(EXIT_SUCCESS);

	return (0);
}
