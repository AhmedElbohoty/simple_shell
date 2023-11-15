#ifndef SHELL_HEADER
#define SHELL_HEADER

/* Libs */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Helpers */
void *_calloc(unsigned int nmemb, unsigned int size);
int is_empty_line(char *buff);

/* String helpers */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *str_concat(char *dest, char *src);
char **_split(char *str, char *sep);

/* Environments helpers */
char *_getenv(char *env_var);
void _env(void);

char *get_cmd_path(char *command);
int execute(char **args);

extern char **environ;

#endif

