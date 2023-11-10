#include "shell.h"
int _exe(char **cmd, char **argv,int i)
{
	pid_t child;
	int status;
	char* full_path;
	full_path = get_path(cmd[0]);
	if (!full_path)
	{
	error(argv[0], cmd[0], i);
	freearr2(cmd);
	return(127);
	}
    child = fork();
    if (child == 0)
    {
        if(execve(full_path, cmd, environ) == -1)
        {
		free(full_path), full_path = NULL;
		freearr2(cmd);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        free(full_path), full_path = NULL;
	freearr2(cmd);
    }
    return (WEXITSTATUS(status));
}
