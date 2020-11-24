#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>
extern char **environ;

typedef struct stat stat_t;

/**
 * struct builtins - commands
 * @cmd: command;
 * @cmd_f: command and funtion;
 */
typedef struct builtins
{
const char *cmd;
int (*cmd_f)(char **args);
} builtins_t;

int _getline(char **lineptr, size_t *n, FILE *stream);

void _puts(char *str);

void _fputs(int fd, char *str);

int _putchar(char c);

char *_getpath(void);

int exec_cmd(char *cmd, char **args);

int loop(char *argv);

void handler(int);

int get_env(char **nothing);

int get_exit(char **args);

int _operator(char **args);

char *_strcat(char *dest, char *src);

int _strcmp(const char *s1, const char *s2);

char *_strcpy(char *dest, const char *src);

char *_strdup(const char *str);

int isanum(char *str);

unsigned int _strspn(char *s, char *accept);

int _atoi(char *str);

char *strcatnum(char *str, int num);
#endif
