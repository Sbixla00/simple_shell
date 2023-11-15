#include "shell.h"
/**
 * afdal_cd - change the current working directory
 *
 * @cmd: the command name and arguments
 * @argv: the command arguments
 * @status: the exit status of the command
 * @i: the index of the current command in the command list
 *
 * Return: void
*/
void afdal_cd(char **cmd, char *argv, int *status, int i)
{
	char cwd[PATH_MAX], *tmp = NULL, *tmp1 = NULL;

	getcwd(cwd, sizeof(cwd));
	if (!cmd[1])
	{
		tmp = _strdup(cwd), tmp1 = _strdup(getenv("HOME"));
		chdir(tmp1);
		setenv("OLDPWD", tmp, 1), setenv("PWD", tmp1, 1);
		*status = 0;
	}
	else if (_strcmp(cmd[1], "-") == 0)
	{
		tmp = _strdup(getenv("OLDPWD") ? getenv("OLDPWD") : "/");
		tmp1 = _strdup(cwd);
		chdir(tmp);
		setenv("OLDPWD", tmp1, 1), setenv("PWD", tmp, 1);
		write(STDOUT_FILENO, tmp, _strlen(tmp));
		write(STDOUT_FILENO, "\n", 1), *status = 0;
	}
	else
	{
		tmp = _strdup(cwd);
		tmp1 = _strdup(cmd[1]);
		if (chdir(cmd[1]) == 0)
		{
			setenv("OLDPWD", tmp1, 1);
			setenv("PWD", tmp, 1);
			*status = 0;
		}
		else
		{
			error_cd(argv, tmp1, i);
			*status = 2;
		}
	}
	free(tmp), tmp = NULL;
	free(tmp1), tmp1 = NULL;
	freearr2(cmd);
}
