#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "shell.h"

/**
 * print - Print the message
 * @msg: the message to print
 *
 * Return: Nothing
 */
void print(char *msg)
{
	write(STDERR_FILENO, msg, _strlen(msg));
}

/**
 * print_error - Print the error
 * @filename: the name of file
 *
 * Return: Nothing
 */
void print_error(char *filename)
{
	write(STDERR_FILENO, filename, _strlen(filename));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, strerror(errno), _strlen(strerror(errno)));
	write(STDERR_FILENO, "\n", 1);
}
