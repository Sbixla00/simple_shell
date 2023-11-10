#include "shell.h"
char *_itoa(int n)
{
	char buffer [20];
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
	return (_strdup (buffer));
}

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
