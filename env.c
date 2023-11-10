#include "shell.h"
char* get_env(char* cmd)
{
    char* tmp, *full_path, *token;
    int i = 0;

    if (!cmd)
        return (NULL);

    for (i = 0; environ[i]; i++)
    {
        tmp = _strdup(environ[i]);
        token = strtok(tmp, "=");
        if (_strcmp(token, cmd) == 0)
        {
            token = strtok(NULL, "\n");
            full_path = _strdup(token);
            free(tmp), tmp = NULL;
            return (full_path);
        }
        free(tmp), tmp = NULL;
    }
    return (NULL);
}
