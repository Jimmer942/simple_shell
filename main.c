#include "shell.h"
/**
 * main - mini shell
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char *line, line2[200];
	char **com;
	pid_t pid;
	int e, cont = 0;
	(void)ac;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		cont ++;
		write(STDIN_FILENO, "$ ", 2);
		line = readc();
		line = comments(line);
		_cpy(line2, line);
		com = split_command(line);
		if(line[0] == '\n')
			continue;
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
		pid = fork();
		if (!pid)
		{
			execute(line2);
			break;
		}
		else if (pid < 0)
		{
			perror("fork");
			exit(-1);
		}
		else
		{
			wait(NULL);
		}
		free(line);
	}
	return (0);
}
