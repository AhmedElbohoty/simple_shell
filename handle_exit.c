#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include <errno.h>

/**
 * handle_exit - handle exit function
 * @status: exit status
 *
 * Return: Nothing
 */
void handle_exit(char *status)
{
	int num;

	if (!status)
		exit(EXIT_SUCCESS);

	num = _atoi(status);

	if (!num)
		exit(2);
	else
		exit(num);
}
