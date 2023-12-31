#include "shell.h"
/**
 * freearr2 - Frees up the memory allocated to a
 * two-dimensional array of characters.
 *
 * @cmd: A pointer to a pointer to the array of characters to be freed.
*/
void freearr2(char **cmd)
{
	int i;

	if (!cmd)
	return;
	for (i = 0; cmd[i]; i++)
	{
		free(cmd[i]);
		(cmd)[i] = NULL;
	}
	free(cmd);
}
/**
 * _strcat - concatenates two strings
 *
 * @dest: the destination string
 * @src: the source string
 *
 * Return: a pointer to the destination string
*/
void _strcat(char *dest, char *src)
{
	int len2, c;

	len2 = _strlen(dest);
	for (c = 0; src[c]; c++)
	dest[len2++] = src[c];
	dest[len2] = '\0';
}
