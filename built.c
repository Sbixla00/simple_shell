#include "shell.h"
/**
 * built_check - checks if a command is built-in and executes it if so
 *
 * @cmd: the name of the command
 * @argv: an array of arguments to the command
 * @status: a pointer to an integer that will be
 * set to the exit status of the command
 * @i: the index of the command in the argv array
 *
 * Return: 1 if the command is built-in and was executed, 0 otherwise
*/
void built_check(char **cmd, char **argv, int *status, int i)
{
	char err[] = "unsetenv: variable not found"
	, err1[] = "setenv: insufficient memory";

	if (_strcmp("exit", cmd[0]) == 0)
	_exitcmd(cmd, argv, status, i);
	else if (_strcmp("env", cmd[0]) == 0)
	_env(cmd, status);
	else if (_strcmp("cd", cmd[0]) == 0)
	afdal_cd(cmd, argv[0], status, i);
	else if (_strcmp("setenv", cmd[0]) == 0)
	{
		setenv(cmd[1], cmd[2], 1);
		write(SRDERR_FILENO, err1, _srtlen(err1));
	}
	else if (_strcmp("unsetenv", cmd[0]) == 0)
	{
		unsetenv(cmd[1]);
		write(SRDERR_FILENO, err, _srtlen(err));
	}
}
/**
 * _env - Retrieves the value of an environment variable
 *
 * @cmd: The name of the environment variable to retrieve
 *
 * @status: The hjhhfjgjrhjtjhjj
 *
 * Return: The value of the requested environment variable,
 * or `NULL` if the environment variable does not exist
*/
void _env(char **cmd, int *status)
{
	int x;

	for (x = 0; environ[x]; x++)
	{
		write(STDOUT_FILENO, environ[x], _strlen(environ[x]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearr2(cmd);
	*status = 0;
}
/**
 * _exitcmd - Terminates the shell program with a specified exit status
 *
 * @cmd: The command array containing the `exit` keyword
 * @argv: The command arguments (unused for this function)
 * @status: The pointer to the integer to store the exit status
 * @i: The index of the `exit` command in the command array
 *
 * Return: Always returns 1 to indicate the `exit` command was executed
*/
void _exitcmd(char **cmd, char **argv, int *status, int i)
{
	int new_value = *status;
	char *index, msg[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (is_positive_number(cmd[1]))
		new_value = _atoi(cmd[1]);
		else
		{

			index = _itoa(i);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]) + 1);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index) + 1);
			write(STDERR_FILENO, msg, _strlen(msg) + 1);
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]) + 1);
			write(STDERR_FILENO, "\n", 1);
			free(index), index = NULL;
			freearr2(cmd);
			*status = 2;
			return;

		}
	}
	freearr2(cmd);
	exit(new_value);
}
/**
 * is_positive_number - Determines whether a
 * given string represents a positive integer
 *
 * @str: The string to be evaluated
 *
 * Return: 1 if the string represents a valid positive integer, 0 otherwise
*/
int is_positive_number(char *str)
{
	if (str == NULL || *str == '\0')
	{
	return (0);
	}

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/**
 * _atoi - Converts a string representation of an integer into a numeric value
 *
 * @str: The string representation of the integer
 *
 * Return: The converted integer value,
 * or 0 if the string does not represent a valid integer
*/
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; str[i] != '\0'; ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		else
		{
			break;
		}
	}
	return (result * sign);
}
