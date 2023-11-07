#ifndef SHELL_HEADER
#define SHELL_HEADER
#include <sys/types.h>

void execute_cmd(char *command, char **cmd, char *filename);
char **tokenizer(char *str);
size_t tokens_count(char *str, char *delim);
char **words_list(char *str, char *delim);
void handle_cmds(char **argv, char *filename, char **env);
char *get_cmd_path(char *command);
void handle_exit(char *status);

/* String helpers */
void replace_char(char *str, char c1, char c2);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _isdigit(int n);
int _atoi(char *s);
char *_strchr(char *s, char c);

/* All environments vars */
int _setenv(char **argv);
int _unsetenv(char *name);
void _env(char **env);

/* Print helpers */
void print(char *filename);
void print_error(char *filename);

#endif /* End of SHELL_HEADER */
