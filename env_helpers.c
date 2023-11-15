#include "shell.h"

/**
 * _env - print all environments variables
 *
 * Return: Nothing
 */
void _env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * _getenv - get env variables.
 * @env_var: pointer to the environment
 *
 * Return: lists of environments
 */
char *_getenv(char *env_var)
{
	int status, i = 0, j;

	while (environ[i])
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != env_var[j])
				status = 0;
		}

		if (status == 1)
			break;
		i++;
	}

	return (&environ[i][j + 1]);
}

