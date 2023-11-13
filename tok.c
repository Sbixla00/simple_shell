#include "shell.h"
/**
 * token - Tokenizes a string into an array of strings.
 *
 * @line: The string to tokenize.
 *
 * Return: A pointer to an array of pointers to the
 * tokenized strings, or NULL if memory allocation fails.
*/
char **token(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int cpt = 0, i = 0;

	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;

	command = malloc(sizeof(char *) * (cpt + 1));
	if (!command)
	{
		free(line);
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line);
	command[i] = NULL;
	return (command);
}
