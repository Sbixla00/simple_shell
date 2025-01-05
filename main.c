#include "shell.h"
/**
 * main - Entry point for the program.
 *
 * @ac: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: The program's exit status.
*/
int main(int ac, char **argv)
{
	char *line = NULL, **cmd = NULL;
	int status = 0, i = 0;
	(void)ac;
	while (1)
	{
		line = get_line();
		if (!line)
		{
			if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		i++;
		cmd = token(line);
		if (!*cmd)
		continue;
		if (_check(cmd) == 1)
		{
			built_check(cmd, argv, &status, i);
		}
		else
		status = _exe(cmd, argv, i);
	}
}
