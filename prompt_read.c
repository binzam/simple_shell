#include "shell.h"

/**
 * _prompt - writes a prompt, "$"
 *
 * Return: 0 (Success)
 */
int _prompt(void)
{
	char *prompt = "$ ";
	ssize_t writecount = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		writecount = write(STDOUT_FILENO, prompt, 2);
		if (writecount == -1)
			exit(0);
	}
	return (0);
}

/**
 * _read - reads stdin and stores it in a buffer
 * Description: Reads a line from stdin,
 *              removes any trailing new line or tab,
 *              and stops at a '#' character preceded by a space.
 * Return: a pointer to the buffer
 */
char *_read(void)
{
	ssize_t count = 0;
	size_t n = 0;
	char *buff = NULL;
	int i = 0;

	count = getline(&buff, &n, stdin);
	if (count == -1)
	{
		free(buff);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buff[count - 1] == '\n' || buff[count - 1] == '\t')
		buff[count - 1] = '\0';
		for (i = 0; buff[i]; i++)
		{
			if (buff[i] == '#' && buff[i - 1] == ' ')
			{
				buff[i] = '\0';
				break;
			}
		}
	return (buff);
}

