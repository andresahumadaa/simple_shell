#include "holberton.h"
/**
 * exec_cmd - executes a command
 * @cmd: Command for execute
 * @args: Arguments receive
 * Return: 0 success
 */
int exec_cmd(char *cmd, char **args)
{
char *ptr_dir;/* --> directories in PATH*/
char *cp_PATH;/* --> PATH copy, recieves the list of elements in PATH */
char *tmp;
stat_t st;/* --> structure with the file status information */
if (!cmd || !*cmd || !args || !*args || !**args)
{
exit(EXIT_SUCCESS);
}
if (stat(cmd, &st) == 0) /* check if file exist in full command */
{
return (execve(cmd, args, NULL));
}
cp_PATH = _getpath();/* cp_PATH pointing to PATH in ENVIRON */
cp_PATH = _strdup(cp_PATH);
ptr_dir = cp_PATH;/* ptr_dir pointing to cp_PATH */
/* move ptr_dir after "PATH=" in the cp_PATH */
ptr_dir = strtok(cp_PATH, "=");
tmp = malloc(1024);
while ((ptr_dir = strtok(NULL, ":")))
{
_strcpy(tmp, ptr_dir);
tmp = _strcat(tmp, "/");
tmp = _strcat(tmp, cmd);
/* check if file exist in full command */
if (stat(tmp, &st) == 0)
{
free(cp_PATH); /* free cp_PATH */
return (execve(tmp, args, NULL));
}
}
free(tmp);
free(cp_PATH); /* free cp_PATH */
return (-1); /* cmd not found */
}
