#include "shell.h"
/**
 * run - execute command
 * @line2: command
 * @dpath:directories the path
 * Return: 0
 */
void run(char line2[], char *dpath[])
{
	int x;
	char *dpathcmd;
	char **argv = NULL;

	x = (count(line2, ' ')) + 1;
	argv = _calloc(x, sizeof(char));
	splitSpace(argv, line2);
	dpathcmd = checkPath(dpath, argv[0]);
	if (dpathcmd == NULL)
		write(1, ": not found\n", 12);
	else
		execve(dpathcmd, argv, environ);
}
/**
 * runsemicolon - execute two command
 * @copy: comand complete
 * @dpath: directory path
 * Return: 0
 */
void runsemicolon(char copy[], char *dpath[])
{
	int x, a, b;
	char *dpathcmd, *ex1, *ex2;
	char *ppp[2], **argv1 = NULL, **argv2 = NULL;
	pid_t pid2;

	split(copy, ppp, ";");
	a = _strlen(ppp[0]);
	b = _strlen(ppp[1]);

	ex1 = _calloc(a, sizeof(char));
	ex2 = _calloc(b, sizeof(char));
	_strcpy(ex1, ppp[0]);
	_strcpy(ex2, ppp[1]);

	x = (count(ex1, ' ')) + 1;
	argv1 = _calloc(x, sizeof(char));

	splitSpace(argv1, ex1);
	dpathcmd = checkPath(dpath, argv1[0]);
	if (dpathcmd == NULL)
		write(1, ": not found\n", 12);
	else
	pid2 = fork();
	if (!pid2)
	{
		execve(dpathcmd, argv1, environ);
	}
	else if	(pid2 < 0)
	{
		perror("fork");
		exit(-1);
	}
	else
	{
		wait(NULL);
	}

	x = (count(ex2, ' ')) + 1;
	argv2 = _calloc(x, sizeof(char));

	splitSpace(argv2, ex2);
	dpathcmd = checkPath(dpath, argv2[0]);
	if (dpathcmd == NULL)
		write(1, ": not found\n", 12);
	else
		execve(dpathcmd, argv2, environ);

}
/**
 * OO - execute two command
 * @copy: comand complete
 * @dpath: directory path
 * Return: 0
 */
void OO(char copy[], char *dpath[])
{
	int x, a, b;
	char *dpathcmd, *ex1, *ex2;
	char *ppp[2], **argv1 = NULL, **argv2 = NULL;
	pid_t pid2;

	split(copy, ppp, "|");
	a = _strlen(ppp[0]);
	b = _strlen(ppp[1]);

	ex1 = _calloc(a, sizeof(char));
	ex2 = _calloc(b, sizeof(char));
	_strcpy(ex1, ppp[0]);
	_strcpy(ex2, ppp[1]);

	x = (count(ex1, ' ')) + 1;
	argv1 = _calloc(x, sizeof(char));

	splitSpace(argv1, ex1);
	dpathcmd = checkPath(dpath, argv1[0]);
	if (dpathcmd == NULL)
		write(1, ": not found\n", 12);
	else
	pid2 = fork();
	if (!pid2)
	{
		execve(dpathcmd, argv1, environ);
	}
	else if	(pid2 < 0)
	{
		perror("fork");
		exit(-1);
	}
	else
	{
		wait(NULL);
	}

	x = (count(ex2, ' ')) + 1;
	argv2 = _calloc(x, sizeof(char));

	splitSpace(argv2, ex2);
	dpathcmd = checkPath(dpath, argv2[0]);
	if (dpathcmd == NULL)
		write(1, ": not found\n", 12);
	else
		execve(dpathcmd, argv2, environ);

}

/**
 * YY - execute two command
 * @copy: comand complete
 * @dpath: directory path
 * Return: 0
 */
void YY(char copy[], char *dpath[])
{
	int x, a, b;
	char *dpathcmd, *ex1, *ex2;
	char *ppp[2], **argv1 = NULL, **argv2 = NULL;
	pid_t pid2;

	split(copy, ppp, "|");
	a = _strlen(ppp[0]);
	b = _strlen(ppp[1]);

	ex1 = _calloc(a, sizeof(char));
	ex2 = _calloc(b, sizeof(char));

	_strcpy(ex1, ppp[0]);
	_strcpy(ex2, ppp[1]);

	x = (count(ex1, ' ')) + 1;
	argv1 = _calloc(x, sizeof(char));

	splitSpace(argv1, ex1);
	dpathcmd = checkPath(dpath, argv1[0]);
	if (dpathcmd == NULL)
	{
		write(1, ": not found\n", 12);
		return;
	}
	else
	pid2 = fork();
	if (!pid2)
	{
		execve(dpathcmd, argv1, environ);
	}
	else if	(pid2 < 0)
	{
		perror("fork");
		exit(-1);
	}
	else
	{
		wait(NULL);
	}

	x = (count(ex2, ' ')) + 1;
	argv2 = _calloc(x, sizeof(char));

	splitSpace(argv2, ex2);
	dpathcmd = checkPath(dpath, argv2[0]);
	if (dpathcmd == NULL)
		write(1, ": not found\n", 12);
	else
		execve(dpathcmd, argv2, environ);

}

/**
 * splitSpace - cut each space
 * @argv: array save cut
 * @line2: name of filecommand complete
 * Return: 0
 */
void splitSpace(char *argv[], char line2[])
{
	char *puntero;
	int i = 0;

	puntero = strtok(line2, " ");
	while (puntero)
	{
		argv[i] = puntero;
		puntero = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
}
/**
 * split - cut each delimiter
 * @line2: command
 * @slicedCommand: array save cut
 * @c: delimiter
 * Return: 0
 */
void split(char line2[], char *slicedCommand[], char c[])
{
	char *puntero;
	int i = 0;

	puntero = strtok(line2, c);
	while (puntero)
	{
		slicedCommand[i] = puntero;
		puntero = strtok(NULL, c);
		i++;
	}
}
