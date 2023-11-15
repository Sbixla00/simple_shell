#include "shell.h"
/**
 * get_line - Reads a line of input from the standard input stream.
 *
 * @void
 *
 * Return: A pointer to a dynamically allocated buffer
 * containing the line of input,
 * or `NULL` if the input stream is empty or an error occurs.
*/
char *get_line(void)
{
	size_t len = 0;
	char *line = NULL;
	ssize_t c;

	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);
	c = getline(&line, &len, stdin);
	if (c == -1)
	{
		free(line), line = NULL;
		return (NULL);
	}
	return (line);
}
