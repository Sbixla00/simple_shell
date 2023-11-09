#include "shell.h"

char* _strdup(const char *str)
{
    int len  = _strlen(str);
    char* dup = malloc(len + 1);
    int  n = 0;

    while(str[n])
    {
        dup[n] = str[n];
        n++;
    }
    dup[n] = '\0';
    return (dup);
}

int _strcmp(char *s1, char* s2)
{
	    int len1 = _strlen(s1);
	        int len2 = _strlen(s2);
		    int i = 0;
        if (len2 != len1)
   	return 1;
	while (s1[i] == s2[i]) 
	{
	if (s1[i] == '\0') 
	{
      		return 0;
	}
	i++;
	}
		      
	       return (1);
}



char *_strcat(char *dest, char* src)
{
    char* cat;
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


int _strlen(const char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return (i);
}
void _strcpy(char *dest, char* src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
