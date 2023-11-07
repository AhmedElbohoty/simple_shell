#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "shell.h"

/**
 * main - Initialize the shell
 * @argc: The arguments count
 * @argv: The arguments vector
 * @env: The environments vector
 *
 * Return: 0 (Success)
 * Description:
 * 1- Check if data comes from non-terminal source.
 * 2- Print prompt symbol.
 * 3- Get line from user.
 * 4- Replace '\n' with '\0'.
 * 5- If user clicks enter, repeat
 * 6- If the command file is not exist, show error and repeat
 */
int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	char *buff = NULL, **args, *prompt_symbol = "($) ";
	int non_term = 0;
	size_t buff_size = 0;
	ssize_t line = 0;

	signal(SIGINT, SIG_IGN);

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
			print_error(argv[0]);
			exit(EXIT_FAILURE);
		}

		if (buff[0] == '\n')
			continue;

		replace_char(buff, '\n', '\0');

		args = tokenizer(buff);

		handle_cmds(args, argv[0], env);
	}

	free(buff);
	free(args);
	return (0);
}
