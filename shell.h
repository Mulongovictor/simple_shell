#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char** environ;

char *_strtok(char *str, char *deli);
unsigned int is_deli(char c, char *arraydeli);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
int _strcmp(char *s1,char *s2);
char *_strcat(char *desti, const char *src);

#endif /*shell .h*/
