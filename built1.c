#include "shell.h"
/**
 * _check - Checks for syntax errors in a
 * command and handles built-in commands
 *
 * @cmd: The command array to be checked
 *
 * Return: 1 if the command is valid
 * or built-in and was executed, 0 otherwise
*/
int _check(char **cmd)
{
	char *built_tst[] = {"env", "cd", "unsetenv", "setenv", "exit", NULL};
	int i;
	if(cmd && !*cmd)
		return 0;
	for (i = 0; built_tst[i]; i++)
	{
		if (_strcmp(cmd[0], built_tst[i]) == 0)
		return (1);
	}
	return (0);
}
