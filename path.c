#include "shell.h"

/**
* _splitPATH - counts the number of paths in a string
* @str: input string
*
* Return: number of PATH
*/
int _splitPATH(char *str)
{
	int i;
	int flag = 1;
	int count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ':' && flag == 1)
		{
			count += 1;
			flag = 0;
		}
		if (str[i + 1] == ':')
		{
			flag = 1;
		}
	}
	return (count);
}

/**
* PATH_strcmp - compares PATH with environ to find PATH
* @s1: pointer PATH string
* @s2: pointer to environ string
* Return: 0(success)
*/
int PATH_strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s2[i] != '='; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}

/**
* _concat - concats three strings with PATH member
* @tmp: array to store concatenated string
* @av: array of user strings
* @tokn: PATH token
* Return: 0(success)
*/
char *_concat(char *tmp, char **av, char *tokn)
{
	int len = 0;

	_memset(tmp, 0, 256);
	len = _strlen(tokn) + _strlen(av[0]) + 2;
	_strcat(tmp, tokn);
	_strcat(tmp, "/");
	_strcat(tmp, av[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}

