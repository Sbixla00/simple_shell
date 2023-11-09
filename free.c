#include "shell.h"

void freearr2(char** cmd)
{
	int i;
    if(!cmd)
    return;
    for (i = 0; cmd[i]; i++)
    {
        free(cmd[i]);
	       (cmd)[i] = NULL;
    }
    free(cmd);
}
