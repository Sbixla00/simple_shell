#include "shell.h"
void error(char* argv, char* cmd, int i)
{
char *num, fnd[] = ": not found\n";

num = _itoa(i);
write(STDERR_FILENO, argv, _strlen(argv));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, num, _strlen(num));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, cmd, _strlen(cmd));
write(STDERR_FILENO, fnd, _strlen(fnd));
free(num), num = NULL;
}
