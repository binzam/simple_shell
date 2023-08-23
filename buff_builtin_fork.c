#include "shell.h"

/**
 * _fullpathbuffer - finds the full path of file by searching through
 *                   a list of directories i na the PATH variable
 * @av: Array of strings
 * @PATH: PATH string
 * @copy: pointer to copy of PATH string
 *
 * Return: a pointer to string to call execve on
 */
char *_fullpathbuffer(char **av, char *PATH, char *copy)
{
char *tokn, *fullpathbuffer = NULL, *concatstr = NULL;
static char tmp[256];
int PATH_count = 0, path_flag = 0, i = 0, tokn_len = 0;
struct stat j;

copy = NULL;
copy = _strdup(PATH);
PATH_count = _splitPATH(copy);
tokn = strtok(copy, ": =");
while (tokn != NULL)
{
concatstr = _concat(tmp, av, tokn);
if (stat(concatstr, &j) == 0)
{
fullpathbuffer = concatstr;
path_flag = 1;
break;
}
if (i < PATH_count - 2)
{
tokn_len = _strlen(tokn);
if (tokn[tokn_len + 1] == ':')
{
if (stat(av[0], &j) == 0)
{
fullpathbuffer = av[0];
path_flag = 1;
break;
}
}
}
i++;
tokn = strtok(NULL, ":");
}
if (path_flag == 0)
fullpathbuffer = av[0];
free(copy);
return (fullpathbuffer);
}

/**
* checkbuiltins - check if first user string is a built-in
* @av: pointer to array of user of strings
* @buffer: pointer to user string
* @exitstatus: exit status of execve
* Return: 1 if user string is equal to env or 0 otherwise
*/
int checkbuiltins(char **av, char *buffer, int exitstatus)
{
int i;

if (_strcmp(av[0], "env") == 0)
{
_env();
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
free(buffer);
return (1);
}
else if (_strcmp(av[0], "exit") == 0)
{
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
free(buffer);
exit(exitstatus);
}
else
return (0);
}

/**
* _forkprocess - create child process to execute based on user input
* @av: pointer to array of user of strings
* @buffer: pointer to user string
* @fullpathbuffer: pointer to user input
*
* Return: 0 on success
*/
int _forkprocess(char **av, char *buffer, char *fullpathbuffer)
{
int i, status, result, exitstatus = 0;
pid_t pid;

pid = fork();
if (pid == -1)
{
perror("Error");
exit(1);
}
if (pid == 0)
{
result = execve(fullpathbuffer, av, environ);
if (result == -1)
{
perror(av[0]);
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
free(buffer);
exit(127);
}
}
wait(&status);
if (WIFEXITED(status))
{
exitstatus = WEXITSTATUS(status);
}
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
free(buffer);
return (exitstatus);
}

