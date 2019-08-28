#include "shell.h"

void errors(int cont, char *var, char *com, char *name)
{
	char *con, *a = "not found\n", *num;
	char *aux = ": ";
	char *st = NULL;
	int i;

	st = _calloc(200, sizeof(char));
	if (!_strcmp("exit", var))
	{
		a = "Illegal number: ";
		num = com;
	}

	con = _itoa(cont);
	_strcat(st, name);
	_strcat(st, aux);
	_strcat(st, con);
	_strcat(st, aux);
	_strcat(st, con);
	_strcat(st, var);
	_strcat(st, a);
	_strcat(st, num);
	_strcat(st, "\n");
	for (i = 0; st[i] != '\0'; i++)
		;
	free(con);
	write(STDIN_FILENO, st, i);
	free(st);
}
