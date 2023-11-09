#include "shell.h"

int main(int ac, char **argv)
{
    char *line = NULL, **cmd = NULL;
    int status = 0;
    (void)ac;
    while(1)
    {
        line = get_line();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "\n", 1);
            return (status);
        }
        cmd = token(line);
        if (!cmd)
        continue;

        status = _exe(cmd, argv);
    }
}
