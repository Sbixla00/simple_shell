#include "shell.h"
void _setenv(char *name,char *value)
{
	int i;
	char *name_n, *value_n;

	for (i = 0; environ[i]; i++)
	{
		name_n = _strdup(environ[i]);
		value_n = strtok(name_n, "=");

		if (_strcmp(value_n, name) == 0)
		{
			free(environ[i]);
			_strcpy(environ[i], value_n);
			_strcat(environ[i], "=");
			_strcat(environ[i], value);
			_strcat(environ[i], "\0");
			free(name_n);
		}
		free(name_n);
	}
	environ = realloc(environ, sizeof(char*) * (i + 2));
	_strcpy(environ[i], value_n);
	_strcat(environ[i], "=");
	_strcat(environ[i], value);
	_strcat(environ[i], "\0");
	environ[i + 1] = NULL;
}
