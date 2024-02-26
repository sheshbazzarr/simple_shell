#include "shell.h"

/**
 * shell_env - prints the current enviroment
 * @args: for unused attribute
 *
 * Return: 0 if successful.
 */
int shell_env(__attribute__((unused))char **args)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}

/**
 * shell_cd - change working directory to the specified directory
 * @args: string of arguments to specify directory to change to
 *
 * Return: 0 if successful, or 1 if not
 */
int shell_cd(char **args)
{
	static char *oldpwd;
	char *dir = args[1];
	char *pwd;

	if (dir == NULL)
	{
		dir  = getenv("HOME");
	}
	if (dir == NULL)
	{
		printf("sh: cd HOME not set\n");
		return (1);
	}
	else if (strcmp(dir, "-") == 0)
	{
		if (oldpwd == NULL)
		{
			printf("sh: cd OLDPWD not set\n");
			return (1);
		}
		dir = oldpwd;
	}
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		perror("getcwd");
		return (1);
	}
	if (chdir(dir) != 0)
	{
		perror("chdir");
		free(pwd);
		return (1);
	}
	if (oldpwd)
	{
		free(oldpwd);
	}
	oldpwd = pwd;
	return (0);
}

/**
 * shell_help - prints help message to user
 * @args: for unused attribute
 *
 * Return: Always 0.
 */
int shell_help(__attribute__((unused))char **args)
{
	printf("Type command names and arguments then hit enter.\n");
	printf("Use the man command for information on other commands.\n");
	return (0);
}

/**
 * shell_exit - exits program
 * @args: exit status(if any)
 *
 * Return: exit with status(if any) else
 */
int shell_exit(char **args)
{
	int status, i = 0;

	if (args[1] == NULL)
	{
		while (args[i])
			free(args[i++]);
		free(args);
		exit(0);
	}
	else
	{
		status = _change(args[1]);
		while (args[++i])
			free(args[i - 1]);
		free(args);
		exit(status);
	}
}
/* this is Built_ins1.c */
