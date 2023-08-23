#include "shell.h"
/**
 * tokenize - split buffer into separate tokens
 *
 * @buffer: pointer to user string
 *
 * Return: an array of pointer to strings
 */
char **tokenize(char *buffer)
{
	char *token;
	int i = 0, word_count = 0;
	char *delimiter = " \n";
	char **av;

	word_count = _splitstring(buffer);
	if (!word_count)
		return (NULL);
	av = malloc((word_count + 1) * sizeof(char *));
	if (av == NULL)
		exit(1);
	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		av[i] = _strdup(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	av[i] = NULL;
	return (av);
}
