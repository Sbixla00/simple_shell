#include "shell.h"
/**
 * error - displays an error message and exits the program
 *
 * @argv: the command-line arguments
 * @cmd: the command that generated the error
 * @i: the index of the current command in the command list
 *
 * Return: void
*/
void error(char *argv, char *cmd, int i)
{
	char *num, fnd[] = ": not found\n";

	num = _itoa(i);
	write(STDERR_FILENO, argv, _strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, num, _strlen(num));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, fnd, _strlen(fnd));
	free(num), num = NULL;
}
/**
 * error_cd - displays an error message related to
 * changing the directory and exits the program
 *
 * @argv: the command-line arguments
 * @cmd: the command that generated the error
 * @i: the index of the current command in the command list
 *
 * Return: void
*/
void error_cd(char *argv, char *cmd, int i)
{
	char *num = _itoa(i);

	write(STDERR_FILENO, argv, _strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, num, _strlen(num));
	write(STDERR_FILENO, ": cd: can't cd to ", _strlen(": cd: can't cd to "));
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, "\n", 1);
	free(num);
}
