#include "shell.h"
/**
 * main - mini shell
 * Return: Always 0.
 */
int main(void)
{
	char *line, *line2, *l;
	pid_t pid;
	int s, e, cont = 0;
	char **com;

Here:
	signal(SIGINT, sigintHandler);
	while (1)
	{
		cont ++;
		write(STDIN_FILENO, "ShellMan$ ", 10);
		line = readc();
		if(line[0] == '\n')
			goto Here;
		line = comments(line);
		_cpy(line2, line);
		com = split_command(line);
		if (!_strcmp("env", com[0]))
		{
			_env();
			continue;
		}
		if (!_strcmp("exit", com[0]))
		{
			e = salir(line, com, cont);
			if (e == -1)
				goto Here;
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
		free(com);
	}
	return (0);
}
