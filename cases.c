#include "shell.h"
/**
 * run - execute command
 * @line2: command
 * @dpath:directories the path
 * @cont: number of commands.
 * @v: command.
 * @t: error of the command.
 * @n: name of the exe.
 * Return: 0
 */
int run(char line2[], char *dpath[], int cont, char *v, char *t, char *n)
{
	int x = 0, ex = 0;
	char *dpathcmd;
	char **argv = NULL;

	x = (count(line2, ' ')) + 2;
	argv = _calloc(x, sizeof(char *));
	splitSpace(argv, line2);
	dpathcmd = checkPath(dpath, argv[0]);
	if (dpathcmd == NULL)
	{
		free(dpathcmd);
		errors(cont, v, t, n);
	}
	else
		ex = execve(dpathcmd, argv, environ);
	free(argv);
	return (ex);
}
/**
 * scolon - execute two command
 * @copy: comand complete
 * @dpath: directory path
 * @cont: number of commands.
 * @v: command.
 * @t: error of the command.
 * @n: name of the exe.
 * Return: 0
 */
int scolon(char copy[], char *dpath[], int cont, char *v, char *t, char *n)
{
	int x = 0, a = 0, b = 0, ex = 0, status = 0;
	char *dpathcmd, *ex1, *ex2;
	char *ppp[2], **argv1 = NULL, **argv2 = NULL;
	pid_t pid2, wpid;
	(void)wpid;

	split(copy, ppp, ";"), a = _strlen(ppp[0]), b = _strlen(ppp[1]);
	ex1 = _calloc(a, sizeof(char *)), ex2 = _calloc(b, sizeof(char *));
	_strcpy(ex1, ppp[0]), _strcpy(ex2, ppp[1]);
	x = (count(ex1, ' ')) + 2, argv1 = _calloc(x, sizeof(char *));
	splitSpace(argv1, ex1), dpathcmd = checkPath(dpath, argv1[0]);
	if (dpathcmd == NULL)
		errors(cont, v, t, n);
	else
	pid2 = fork();
	if (!pid2)
	{
		if (execve(dpathcmd, argv1, environ) == -1)
		{errors(cont, v, t, n);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid2 < 0)
	{errors(cont, v, t, n);
		return (0);
	}
	else
	{
		do {wpid = waitpid(pid2, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	x = (count(ex2, ' ')) + 2;
	argv2 = _calloc(x, sizeof(char *));
	splitSpace(argv2, ex2), dpathcmd = checkPath(dpath, argv2[0]);
	if (dpathcmd == NULL)
		errors(cont, v, t, n);
	else
		ex = execve(dpathcmd, argv2, environ);
	return (ex);
}
/**
 * OO - execute two command
 * @copy: comand complete
 * @dpath: directory path
 * @cont: number of commands.
 * @v: command.
 * @t: error of the command.
 * @n: name of the exe.
 * Return: 0
 */
int OO(char copy[], char *dpath[], int cont, char *v, char *t, char *n)
{
	int x = 0, a = 0, b = 0, ex = 0, status = 0;
	char *dpathcmd, *ex1, *ex2;
	char *ppp[2], **argv1 = NULL, **argv2 = NULL;
	pid_t pid2, wpid;
	(void)wpid;

	split(copy, ppp, "|");
	a = _strlen(ppp[0]), b = _strlen(ppp[1]);
	ex1 = _calloc(a, sizeof(char)), ex2 = _calloc(b, sizeof(char));
	_strcpy(ex1, ppp[0]), _strcpy(ex2, ppp[1]);
	x = (count(ex1, ' ')) + 2, argv1 = _calloc(x, sizeof(char *));
	splitSpace(argv1, ex1), dpathcmd = checkPath(dpath, argv1[0]);
	if (dpathcmd == NULL)
		errors(cont, v, t, n);
	else
	pid2 = fork();
	if (!pid2)
	{
		if (execve(dpathcmd, argv1, environ) == -1)
		{errors(cont, v, t, n);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid2 < 0)
	{errors(cont, v, t, n);
		return (0);
	}
	else
	{
		do {wpid = waitpid(pid2, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	x = (count(ex2, ' ')) + 2, argv2 = _calloc(x, sizeof(char *));
	splitSpace(argv2, ex2), dpathcmd = checkPath(dpath, argv2[0]);
	if (dpathcmd == NULL)
		errors(cont, v, t, n);
	else
		ex = execve(dpathcmd, argv2, environ);
	return (ex);
}

/**
 * YY - execute two command
 * @copy: comand complete
 * @dpath: directory path
 * @cont: number of commands.
 * @v: command.
 * @t: error of the command.
 * @n: name of the exe.
 * Return: 0
 */
int YY(char copy[], char *dpath[], int cont, char *v, char *t, char *n)
{
	int x = 0, a = 0, b = 0, ex = 0, status = 0;
	char *dpathcmd, *ex1, *ex2;
	char *ppp[2], **argv1 = NULL, **argv2 = NULL;
	pid_t pid2, wpid;
	(void)wpid;

	split(copy, ppp, "|");
	a = _strlen(ppp[0]), b = _strlen(ppp[1]);
	ex1 = _calloc(a, sizeof(char)), ex2 = _calloc(b, sizeof(char));
	_strcpy(ex1, ppp[0]), _strcpy(ex2, ppp[1]);
	x = (count(ex1, ' ')) + 2, argv1 = _calloc(x, sizeof(char *));
	splitSpace(argv1, ex1), dpathcmd = checkPath(dpath, argv1[0]);
	if (dpathcmd == NULL)
		errors(cont, v, t, n);
	else
	pid2 = fork();
	if (!pid2)
	{
		if (execve(dpathcmd, argv1, environ) == -1)
		{errors(cont, v, t, n);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid2 < 0)
	{errors(cont, v, t, n);
		return (0);
	}
	else
	{
		do {wpid = waitpid(pid2, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	x = (count(ex2, ' ')) + 2, argv2 = _calloc(x, sizeof(char *));
	splitSpace(argv2, ex2), dpathcmd = checkPath(dpath, argv2[0]);
	if (dpathcmd == NULL)
		errors(cont, v, t, n);
	else
		ex = execve(dpathcmd, argv2, environ);
	return (ex);
}
