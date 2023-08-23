#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

/****** STRING HELPER FUNCTIONS ******/

int _strlen(char *s);
char *_strdup(char *str);
int _splitstring(char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, char *src);

/****** MORE HELPER FUNCTIONS ******/

int _putchar(char c);
void _puts(char *str);
char *_getenv(const char *name);
int _env(void);
char *_memset(char *s, char b, unsigned int n);

/****** READ/WRITE BUFFER FUNCTIONS ******/
int _prompt(void);
char *_read(void);
char *_fullpathbuffer(char **av, char *PATH, char *copy);
int checkbuiltins(char **av, char *buffer, int exitstatus);
int _forkprocess(char **av, char *buffer, char *fullpathbuffer);

/***** TOKENIZE FUNCTION ******/

char **tokenize(char *buffer);

/****** PATH HELPER FUNCTIONS ******/

int _splitPATH(char *str);
int PATH_strcmp(const char *s1, const char *s2);
char *_concat(char *tmp, char **av, char *tokn);

#endif
