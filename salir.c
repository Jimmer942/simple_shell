#include "shell.h"
/**
 * salir - exit the shell.
 * @line: line of commands
 * @cont: number of commands.
 * @com: array of command and arguments.
 * @name: name of the exe.
 * Return: an integer.
**/
int salir(char *line, int cont, char **com, char *name)
{
	int e = 0, i = 0, w = 1;

	if (com[1] == NULL)
	{
		free(line);
		free(com);
		exit(0);
	}
	for (; com[1][i] != '\0'; i++)
	{
		w = _isdigit(com[1][i]);
		if (w == 0)
			break;
	}
	if (w == 1)
		e = _atoi(com[1]);
	else
		e = -1;
	if (e >= 0 && e + 1 > 0)
	{
		free(line);
		free(com);
		exit(e);
	}
	else
	{
		errors(cont, com[0], com[1], name);
		free(line);
		free(com);
		return (-1);
	}
}
