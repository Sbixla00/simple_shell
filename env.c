#include "shell.h"
/**
 * get_env - gets the value of an environment variable
 *
 * @cmd: the name of the environment variable
 *
 * Return: a pointer to the value of the environment variable,
 * or `NULL` if the environment variable does not exist
*/
char *get_env(char *cmd)
{
	char *tmp, *full_path, *token;
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
