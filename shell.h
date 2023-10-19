#ifndef SHELL_H
#define SHELL_H

/***** MACROS *****/
#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFSIZE 10240
#define DELIMITER " \t\r\n\a"

/*** STANDARD LIBRARIES ***/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/******** STRING HANDLER FUNCTIONS **********/

char *_strncpy(char *dest, char *src, int z);
int _strlen(char *z);
int _putchar(char z);
int _atoi(char *z);
void _puts(char *str);
int _strcmp(char *str1, char *str2);
int _isalpha(int z);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int z);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *z, char a);
int _strncmp(const char *str1, const char *str2, size_t z);
char *_strdup(char *str);

/*********** MEMORY HANDLERS ***********/

void free_env(char **env);
void *filling_array(void *z, int y, unsigned int len);
char *_memocpy(char *dest, char *src, unsigned int z);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int previous_size, unsigned int next_size);
void all_freed(char **cmnd, char *lines);

/****** MISCELLANEOUS AND INPUT FUNCTIONS *******/

char *_getline();
char *space(char *strz);
char *enter(char *strng);
void hashtag_handler(char *buffiz);
void prompt(void);
unsigned int is_delim(char c, const char *str);
char *_strtok(char *str1, const char *delim);
int history(char *input);
char **tokenizer(char *usrinput);

/****** FILE ARGUMENT HANDLER FUNCTIONS ******/

void file_read(char *file, char **argv);
void file_treat(char *lines, int count, FILE *fp, char **argv);
void exit_file_handle(char **cmnd, char *lines, FILE *fd);

/****** PARSED ARGUMENT HANDLER FUNCTIONS *****/

char **parse_cmd(char *input);
int handle_builtin(char **cmd, int er);
int check_cmd(char **cmd, char *userinput, int a, char **argv);
void signal_to_handle(int signal);

/******* ERROR HANDLERS ******/

void print_error(char *input, int count, char **argv);
void _prerror(char **argv, int z, char **cmnd);
void error_file(char **argv, int z);

/****** ENVIRONMENT HANDLERS ******/

extern char **environ;
void enviro_creation(char **enviro);
void enviro_free(char **enviro);

/****** PRINTING FUNCTIONS *****/

void print_number(unsigned int z);
void print_number_int(int z);
int echo_printer(char **cmnd);

/******* PATH FINDER *******/

int path_cmnd(char **cmnd);
char *builder(char *tok, char *value);
char *_getenv(char *name);

/******* HELP HANDLERS *******/

void env_helper(void);
void setenv_helper(void);
void unsetenv_helper(void);
void help_history(void);
void all_help(void);
void alias_help(void);
void cd_help(void);
void exit_help(void);
void help_help(void);
int display_helper(char **cmnd, __attribute__((unused))int st);

/****** BUILTIN COMMAND HANDLERS AND EXECUTE ******/

int check_builtin(char **cmd);
int handle_builtin(char **cmd, int st);
void exit_bul(char **cmnd, char *input, char **argv, int z, int stat);
int change_dir(char **cmnd, __attribute__((unused))int st);
int dis_env(__attribute__((unused)) char **cnd,
	    __attribute__((unused)) int st);
int echo_bul(char **cmnd, int st);
int history_dis(__attribute__((unused))char **a,
		__attribute__((unused)) int st);

/****** BUILT-IN COMMANDS STRUCT *****/

/**
 * struct _builtin - Defines a struct that conatins built-in commands
 * with their respective implementation functions
 * @command: - Built-in command
 * @function: - Pointer to custom functions that have
 * similar functionalities as the built-in commands
 */
typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

#endif /*HEADER_H*/


