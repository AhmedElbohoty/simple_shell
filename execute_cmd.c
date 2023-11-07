#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute_cmd - Execute the command
 * @command: the command
 * @argv: the array of arguments
 * @filename: name of file
 *
 * Return: Nothing
 */
void execute_cmd(char *command, char **argv, char *filename)
{
	pid_t child_pid;
	int wstatus;
	char **env = NULL;

	/* Replace the first element of argv with command path */
	argv[0] = command;

	/* Create child process to execute file */
	child_pid = fork();

	if (child_pid == -1) /* If fork failed */
	{
		print_error(filename);
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0) /* Child process */
	{
		if (execve(command, argv, env) == -1)
		{
			print_error(filename);
			exit(EXIT_FAILURE);
		}
	}

	if (child_pid > 1 && waitpid(child_pid, &wstatus, 0) == -1)
	{
		print_error(filename);
		exit(EXIT_FAILURE);
	}
}
