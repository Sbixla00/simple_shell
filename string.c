#include "shell.h"
/**
 * _strdup - Duplicates the specified string.
 *
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string,
 * or `NULL` if memory allocation fails.
*/
char *_strdup(const char *str)
{
	int len  = _strlen(str);
	char *dup = malloc(len + 1);
	int  n = 0;

	while (str[n])
	{
		dup[n] = str[n];
		n++;
	}
	dup[n] = '\0';
	return (dup);
}
/**
 * _strcmp - Compares two strings lexicographically.
 *
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: An integer indicating
 * the relative ordering of the strings:
 *   - A negative value if `s1` is less than `s2`.
 *   - Zero if `s1` is equal to `s2`.
 *   - A positive value if `s1` is greater than `s2`.
*/
int _strcmp(char *s1, char *s2)
{
	int len1 = _strlen(s1);
	int len2 = _strlen(s2);
	int i = 0;

	if (len2 != len1)
	return (1);
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/**
 * _strcat1 - Concatenates two strings.
 *
 * @dest: The destination string where the concatenation will take place.
 * @src: The source string to be appended to the destination string.
 *
 * Return: A pointer to the destination string,
 * pointing to the start of the concatenated string.
*/
char *_strcat1(char *dest, char *src)
{
	char *cat;
	int result;
	int len1, len2, c = 0, i;

	len1 = _strlen(src);
	len2 = _strlen(dest);
	result = len1 + len2;
	cat = malloc(result + 1);

	for (i = 0; src[i]; i++)
	{
		cat[c++] = src[i];
	}
	for (i = 0; dest[i]; i++)
	{
		cat[c++] = dest[i];
	}
	cat[c] = '\0';
	return (cat);
}
/**
 * _strlen - Calculates the length of a null-terminated string.
 *
 * @str: The null-terminated string to measure.
 *
 * Return: The length of the string, excluding the null terminator.
*/
int _strlen(const char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}
/**
 * _strcpy - Copies a null-terminated
 * string from one location to another.
 *
 * @dest: The destination string where the copied string will be stored.
 * @src: The source string to be copied.
 *
 * Return: None.
*/
void _strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
