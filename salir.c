#include "shell.h"
int salir(char *line, int cont, char **com, char *name)
{
	int e;

	com = split_command(line);

	if (com[1] == NULL)
	{
		free(line);
		free(com);
		exit(0);
	}
	e = _atoi(com[1]);
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
