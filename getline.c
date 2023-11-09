#include "shell.h"

char *get_line(void)
{
    size_t len = 0;
    char *line = NULL;
    ssize_t c;
    if (isatty(STDIN_FILENO))
    write(STDOUT_FILENO, "$ ", 2);
    c = getline(&line, &len, stdin);
    if (line == NULL || c == -1)
    {
	free(line);
	    return NULL;
    }
    return (line);
}
