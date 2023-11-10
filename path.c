#include "shell.h"
char *get_path(char *cmd)
{
	struct stat st;
	char* tmp, *val, *full_path;
	int i;
	for(i = 0; cmd[i];i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
			return (_strdup(cmd));
	
			return (NULL);
		} 
	}
	val = get_env("PATH");
	if (!val)
	return (NULL);
	tmp = strtok(val, ":");
	while(tmp)
	{
		full_path = malloc(_strlen(tmp) + 2 + _strlen(cmd));
		_strcpy(full_path,tmp);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);
		if (stat(full_path, &st) == 0)
		{
			free(val), val = NULL;
			return (full_path);
		}
		free(full_path), full_path = NULL;
		tmp = strtok(NULL, ":");
	}
	free(val), val = NULL;
	return (NULL);
}
