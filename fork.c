#include "shell.h"
/**
 * _fork - forks the process.
 * @l2: command line.
 * @l: line to free.
 * @c: number of commands.
 * @com: command.
 * @n: name of the exe.
 * Return: an integer
**/
int _fork(char *l, char **com, char *l2, int c, char *n)
{
	pid_t pid = 0, wpid;
	int status = 0;
	(void)wpid;
	pid = fork();
	if (pid == 0)
	{
		if (execute(l2, c, com[0], com[1], n) == -1)
		{
			errors(c, com[0], com[1], n);
			free(l), free(l2), free(com);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		errors(c, com[0], com[1], n);
		return (0);
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
