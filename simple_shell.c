#include "holberton.h"
/**
 * main - basic shell
 * @argc: argument counter
 * @argv: argument values
 * Return: ?
 */
int main(int argc, char *argv[])
{
int exit_status = EXIT_SUCCESS;
/* Redirect Interrupt signal to handler function */
signal(SIGINT, handler);
exit_status = loop(argv[0]); /*infinite command loop*/
(void)argc;
return (exit_status);
}
/**
 * loop - shell loop
 * @shellname: name of shell
 * Return: Exit status
 */
int loop(char *shellname)
{
char *line = NULL;/* Line pointer for getline funct */
char **args;/* List of Arguments */
int i;/* Arguments' counter */
size_t bufsize = BUFSIZE; /* Size of buffer (line) */
ssize_t nbytes;/* Number of bytes for getline funct */
char *PS1 = PROMPT;/* Char variable for prompt */
int counter = 0;/* loop counter */
pid_t child_pid;/* pocess id */
int istty;/* bool: check if interactive/keyboard */
int exit_status = 0; /* exit status */
int status;/* child's status process */
/* Allocate memory for listing arguments */
args = malloc(NARGS * sizeof(*args));
/* Allocate memory for input data */
/* line = malloc(bufsize * sizeof(*line)); */
while (TRUE) /* Infinite while */
{
counter++;
istty = isatty(STDIN_FILENO);
if (istty == 1)
_puts(PS1); /* Print prompt */
/* Get the number of bytes from getline */
nbytes = getline(&line, &bufsize, stdin);
if (nbytes == EOF) /* Checking for <C-d> */
{
if (istty == 1)
_putchar('\n'); /* go to new line */
break;/* Exit infinite while */
}
line[nbytes - 1] = 0; /* Removing '\n' */
/* args[0] pointing to the input program */
args[0] = strtok(line, SPLITCHARS);
i = 1; /* starting from arg 1 */
/* args array pointng to the program arguments */
while ((args[i] = strtok(NULL, SPLITCHARS)) != NULL)
{
i++; /* Increasing step */
}
/* Check if line was a Enter */
if (args[0] == NULL)
continue;
exit_status = _operator(args);
if (exit_status == 2)
{
myperror(ERROR_EXIT, counter, shellname, args);
continue;
}
child_pid = fork();
if (child_pid > 0)
{
waitpid(child_pid, &status, WCONTINUED | WUNTRACED);
exit_status = WEXITSTATUS(status);
}
else if (child_pid == 0)
{
exec_cmd(args[0], args);
myperror(ERROR_CMD, counter, shellname, args);
exit(127);
}
}
free(line);
free(args); /* Free malloc */
return (exit_status);
}
/**
 * handler - Interruption routine
 * @num: unused variable
 */
void handler(int num)
{
char *PS1 = PROMPT; /* prompt */
_putchar('\n');
_puts(PS1);
(void)num;
}
/**
 * strcatnum - concat int number in string
 * @str: destination string
 * @num: source integer
 * Return: pointer to destination string
 */
char *strcatnum(char *str, int num)
{
int s_idx = 0;
int tens = 1;
unsigned int tmp;
while (str[s_idx])
s_idx++;
if (num < 0)
{
str[s_idx] = '-';
num = -num;
}
tmp = num;
if (num == INT_MIN)
{
tmp++;
}
while (tmp > 9)
{
tens = tens * 10;
tmp = tmp / 10;
}
tmp = num;
while (tens > 0)
{
str[s_idx] = ('0' + tmp / tens);
s_idx++;
tmp %= tens;
tens /= 10;
}
return (str);
}
/**
 * myperror - my print error code
 * @error_code: Error code
 * @counter: Counter Errors
 * @shellname: shellname
 * @args: input arguments
 */
void myperror(int error_code, int counter, char *shellname, char **args)
{
char errmsg[1024] = "";
switch (error_code)
{
case (ERROR_EXIT):
_strcat(errmsg, shellname);
_strcat(errmsg, ": ");
strcatnum(errmsg, counter);
_strcat(errmsg, ": ");
_strcat(errmsg, args[0]);
_strcat(errmsg, ": Illegal number: ");
_strcat(errmsg, args[1]);
_strcat(errmsg, "\n");
_fputs(STDERR_FILENO, errmsg);
break;
case (ERROR_CMD):
_strcat(errmsg, shellname);
_strcat(errmsg, ": ");
strcatnum(errmsg, counter);
_strcat(errmsg, ": ");
_strcat(errmsg, args[0]);
_strcat(errmsg, ": not found\n");
_fputs(STDERR_FILENO, errmsg);
}
}
