#include "shell.h"
/**
 * execute - find in command special caracter and run
 * @line2: command
 * @cont: number of commands.
 * @v: command.
 * @t: error of the command.
 * @n: name of the exe.
 * Return: 0
 */
int execute(char line2[], int cont, char *v, char *t, char *n)
{
	int lengthline2 = _strlen(line2);
	int flaqsc = 0, ex = 0;
	char *copy = NULL;
	char *path;
	char **dpath;

	copy = _calloc(lengthline2 + 1, sizeof(char));
	path = gpath();
	dpath = splitPath(path);
	flaqsc = flaqs(line2);
	_strcpy(copy, line2);
	if (flaqsc == 0)
	{
		ex = run(line2, dpath, cont, v, t, n);
	}
	else if (flaqsc == 1)
	{
		ex = scolon(copy, dpath, cont, v, t, n);
	}
	else if (flaqsc == 3)
	{
		ex = OO(copy, dpath, cont, v, t, n);
	}
	else if (flaqsc == 4)
	{
		ex = YY(copy, dpath, cont, v, t, n);
	}
	free(path);
	free(copy);
	free(dpath);
	return (ex);
}
/**
 * count - count number of delimiter in the command
 * @line2: command
 * @c: delimiter
 * Return: number of the delimiter
 */
int count(char line2[], char c)
{
	int j = 0, k = 0;

	while (line2[j])
	{
		if (line2[j] == c)
			k++;
		j++;
	}
	return (k);
}
