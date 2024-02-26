#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#define TOK_DELIM " \t\r\n\a\""
#define BUFSIZE 1024
extern char **environ;

int _change(char *s);
int _strcmp(char *s1, char *s2);

char *read_line(void);
char **split_line(char *line);
int execute(char **args);
int new_process(char **args);
char *read_stream(void);

int shell_cd(char **args);
int shell_help(__attribute__((unused))char **args);
int shell_exit(char **args);
int shell_env(char **args);
int shell_setenv(char **args);
int shell_unsetenv(char **args);

/**
 * struct builtin - Struct builtin
 *
 * @builtin_str: The command entered
 * @builtin_func: The function called to handle the command
 */
typedef struct builtin
{
	char *builtin_str;
	int (*builtin_func)(char **);
} builtin;

int (*get_function(char *s))(char **args);

#endif
/*This is the header files it must be included in every function */
