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
void _strcat(char *dest, char* src)
{
	int len2, c;
	len2 = _strlen(dest);	
    
	for (c = 0; src[c]; c++)
	dest[len2++] = src[c];
	dest[len2] = '\0';
}
