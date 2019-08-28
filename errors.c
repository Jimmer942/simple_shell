#include "shell.h"
/**
 * errors - prints the error with it's type.
 * @cont: number of commands.
 * @var: command.
 * @type: error of the command.
 * @name: name of the exe.
**/
void errors(int cont, char *var, char *type, char *name)
{
	char *con, *a = "not found", *num;
	char *aux = ": ";
	char *st = NULL;
	int i;

	st = _calloc(200, sizeof(char));
	if (!_strcmp("exit", var))
	{
		a = "Illegal number: ";
		num = type;
	}
	else
		num = "";

	con = _itoa(cont);
	_strcat(st, name);
	_strcat(st, aux);
	_strcat(st, con);
	_strcat(st, aux);
	_strcat(st, var);
	_strcat(st, aux);
	_strcat(st, a);
	_strcat(st, num);
	_strcat(st, "\n");
	for (i = 0; st[i] != '\0'; i++)
		;
	free(con);
	write(STDERR_FILENO, st, i);
	free(st);
}
