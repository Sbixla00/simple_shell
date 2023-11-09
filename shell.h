#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"
extern char **environ;


char *get_line(void);
char **token(char *line);
int _exe(char **cmd,char **argv);

	char* _strdup(const char *str);
	int _strcmp(char *s1, char* s2);
	int _strlen(const char *str);
	char *_strcat(char *dest, char* src);
	void _strcpy(char *dest, char* src);

	void freearr2(char** cmd);


#endif
