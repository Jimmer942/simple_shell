#include "shell.h"
/**
 * main - mini shell
 * @ac: number of arguments.
 * @av: arguments.
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char *line = NULL, line2[200];
	char **com = NULL;
	int e = 0, cont = 0;
	(void)ac;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		cont++;
		write(STDIN_FILENO, "$ ", 2);
		line = readc();
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		line = comments(line), _cpy(line2, line);
		com = split_command(line);
		if (!_strcmp("env", com[0]))
		{
			_env();
			continue;
		}
		if (!_strcmp("exit", com[0]))
		{
			e = salir(line, cont, com, av[0]);
			if (e == -1)
				continue;
		}
		if (line[0] != '/')
			_fork(line2, cont, com[0], com[1], av[0]);
		else
			execute_command(com, line, cont, com[0], com[1], av[0]);
		free(line), free(com);
	}
	return (0);
}
