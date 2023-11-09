#include "shell.h"
int _exe(char **cmd, char **argv)
{
	pid_t child;
	int status;

    child = fork();
    if (child == 0)
    {
        if(execve(cmd[0], cmd, environ) == -1)
        {
	    perror(argv[0]);
	    freearr2(cmd);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        freearr2(cmd);
    }
    return (WEXITSTATUS(status));
}
