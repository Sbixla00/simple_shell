#include "shell.h"
/**
 * _itoa - dsgghgdhrvrggnrvtrggg
 *
 * @n: string
 *
 * Return: integer value of the string,
 * or 0 if the string is not a valid integer.
*/
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
	buffer[i++] = '0';
	else
	{
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	}

	buffer[i] = '\0';
	reverse_string(buffer, i);
	return (_strdup(buffer));
}
/**
 * reverse_string - reverses the characters in a string
 *
 * @str: the string to reverse
 * @len: the length of the string
 *
 * Return: void
*/
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
