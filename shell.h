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
#include <sys/stat.h>
#include <limits.h>

#define DELIM " \t\n"
extern char **my_environ;
extern char **environ;
extern char *built_tst[];



char *get_line(void);
char **token(char *line);
int _exe(char **cmd,char **argv, int i);
char *get_env(char* cmd);
char *get_path(char *cmd);

int _check(char** cmd);
void built_check(char** cmd, char** argv, int *status, int i);
void _env(char **cmd, int* status);
void _exitcmd(char **cmd,char **argv, int* status, int i);
void afdal_cd(char **cmd, char *argv, int *status, int i);
void _setenv(char *name, char *value);
void error_cd(char* argv, char* cmd, int i);


	char *_strdup(const char *str);
	int _strcmp(char *s1, char* s2);
	int _strlen(const char *str);
	void _strcpy(char *dest, char* src);
	void _strcat(char *dest, char* src);
	
	char *_itoa(int n);
	void reverse_string(char *str, int len);
	void error(char* argv, char* cmd, int i);
	void freearr2(char** cmd);
	int _atoi(char *str);
	int is_positive_number(char *str);
#endif
