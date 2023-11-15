#include "shell.h"

/**
 * execute - execute command.
 * @args: Double pointer to arguments.
 *
 * Return: exit status.
 */
int execute(char **args)
{
	int id = fork();
	int status = 0;

	if (id == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror("Error");
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}

	return (status);
}

