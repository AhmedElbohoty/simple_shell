#include <stdlib.h>
#include <sys/stat.h>
#include "shell.h"
#include <string.h>

/**
 * get_cmd_path - Get the command path from env
 * @command: the command
 *
 * Return: path to the command
 */
char *get_cmd_path(char *command)
{
	char *path, *path_copy, *file_path;
	char *token;
	int command_len;
	int dir_len;
	struct stat fileState;

	path = getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	command_len = _strlen(command);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		dir_len = _strlen(token);
		file_path = malloc(command_len + dir_len + 2);
		strcpy(file_path, token);
		strcat(file_path, "/");
		strcat(file_path, command);
		strcat(file_path, "\0");

		if (stat(file_path, &fileState) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			token = strtok(NULL, ":");
		}
	}

	free(path_copy);
	if (stat(command, &fileState) != 0)
		return (NULL);

	return (command);
}
