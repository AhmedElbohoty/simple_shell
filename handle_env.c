#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

/**
 * _setenv - set new env variables
 * @argv: Double pointer to commands
 *
 * Return: 0 (Success)
 *        -1 (Failure)
 */
int _setenv(char **argv)
{
	char *name = argv[1], *value = argv[2];

	if (name == NULL || value == NULL)
		return (-1);

	if (_strlen(name) == 0)
		return (-1);

	if (_strchr(name, '='))
		return (-1);

	return (setenv(name, value, 1));
}

/**
 * _unsetenv - unset env variables
 * @name: pointer to the name
 *
 * Return: 0 (Success)
 *        -1 (Failure)
 */
int _unsetenv(char *name)
{
	if (name == NULL)
		return (-1);

	return (unsetenv(name));
}

/**
 * _env - print all environments
 * @env: pointer to the environments vars
 *
 * Return: Nothing
 */
void _env(char **env)
{
	int i = 0;

	while (env[i])
	{
		print(env[i]);
		print("\n");
		i++;
	}
}
