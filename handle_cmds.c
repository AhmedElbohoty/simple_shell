#include <stdlib.h>
#include <sys/stat.h>
#include "shell.h"

/**
 * handle_cmds - handle commands
 * @argv: Double pointer to commands
 * @filename: name of file
 * @env: Double pointer to environments
 *
 * Return: Nothing
 */
void handle_cmds(char **argv, char *filename, char **env)
{
	struct stat statbuf;
	char *command = NULL;

	if (argv[0])
	{
		if (_strcmp(argv[0], "exit") == 0)
			handle_exit(argv[1]);
		else if (_strcmp(argv[0], "setenv") == 0)
			_setenv(argv);
		else if (_strcmp(argv[0], "unsetenv") == 0)
			_unsetenv(argv[1]);
		else if (_strcmp(argv[0], "env") == 0)
			_env(env);
		else
		{

			command = get_cmd_path(argv[0]);

			if (!command)
			{
				print_error(filename);
			}
			else if (stat(command, &statbuf) != 0)
			{
				print_error(filename);
			}
			else
			{
				execute_cmd(command, argv, filename);
			}
		}
	}
}
