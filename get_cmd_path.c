#include "shell.h"

/**
 * get_cmd_path - Get the command path
 * @command: The pointer to the command
 *
 * Return: - If success, returns the path to command.
 *         - Else, return NULL.
 */
char *get_cmd_path(char *command)
{
	struct stat info;
	int i = 0, len = 0;
	char *path = _getenv("PATH"), *cpy, **split, *concat = NULL;

	if (stat(command, &info) == 0)
		return (command);

	cpy = malloc(_strlen(path) + 1);
	cpy = _strcpy(cpy, path);
	split = _split(cpy, ":");

	while (split[i])
	{
		len = _strlen(split[i]);
		if (split[i][len - 1] != '/')
			concat = str_concat(split[i], "/");

		concat = str_concat(split[i], command);
		if (stat(concat, &info) == 0)
			break;

		i++;
	}

	free(cpy);

	if (!split[i])
	{
		free(split);
		return (NULL);
	}

	free(split);

	return (concat);
}

