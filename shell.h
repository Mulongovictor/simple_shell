#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

char *_strtok(char *str, char *deli);
unsigned int is_deli(char c, char *arraydeli);

#endif /*shell .h*/
