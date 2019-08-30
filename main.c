#include "shell.h"
/**
 * main - mini shell
 * @ac: number of arguments.
 * @av: arguments.
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char *line = NULL, *line2 = NULL;
	char **com = NULL;
	int e = 0, cont = 0;
	(void)ac;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		cont++;
		write(STDIN_FILENO, "$ ", 2);
		line = readc(), line = comments(line);
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		line2 = _calloc(_strlen(line) + 1, sizeof(char));
		_cpy(line2, line);
		com = split_command(line);
		if (!_strcmp("env", com[0]))
		{_env(com);
			free(line), free(line2), free(com);
			continue;
		}
		if (!_strcmp("exit", com[0]))
		{
			e = salir(line, line2, cont, com, av[0], e);
			if (e == 2)
			{
				free(line), free(line2), free(com);
				continue;
			}
		}
		if (line[0] != '/')
			_fork(line, com, line2, cont, av[0]);
		else
			execute_command(com, line, cont, com[0], com[1], av[0]);
		free(line), free(com), free(line2);
	}
	return (0);
}
