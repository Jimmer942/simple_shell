#ifndef shell_l
#define shell_l

#define PATH_MAX 4096
#include <limits.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <fcntl.h>

extern char **environ;

char *_cpy(char *dest, char *src);
char *readc(void);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
int count(char line2[], char c);

int space(char dig[]);
int flaqs(char dig[]);
void split(char line2[], char *slicedCommand[], char c[]);
void splitSpace(char *argv[], char line2[]);
int run(char line[], char *dpath[], int cont, char *v, char *t, char *n);
int scolon(char copy[], char *dpath[], int cont, char *v, char *t, char *n);
int OO(char copy[], char *dpath[], int cont, char *v, char *t, char *n);
int YY(char copy[], char *dpath[], int cont, char *v, char *t, char *n);

void sigintHandler(int sig_num);

char _strtokmao(char *line, char *delim);

int execute(char line2[], int cont, char *v, char *t, char *n);

char *checkPath(char **dpath, char *argv0);
char *gpath();
char **splitPath(char *path);
char *unePath(char *dpath, char *argv0);

void _env(char **com);
int salir(char *line, char *line2, int cont, char **com, char *name, int e);

void errors(int cont, char *var, char *com, char *name);
char *_itoa(int n);
int _atoi(char *s);
void *_calloc(unsigned int nmemb, unsigned int size);
char **split_command(char *line);
char *comments(char *line);
int _isdigit(int c);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int execute_command(char **args, char *p, int cont, char *v, char *t, char *n);
int _fork(char *l, char **com, char *l2, int c, char *n);

#endif
