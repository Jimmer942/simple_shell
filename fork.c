#include "shell.h"
/**
 * _fork - forks the process.
 * @line2: command line.
 * execute_command - exe.
 * @cont: number of commands.
 * @v: command.
 * @t: error of the command.
 * @n: name of the exe.
**/
int _fork(char *line2, int cont, char *v, char *t, char *n)
{
	pid_t pid = 0, wpid;
	int status = 0;
	(void)wpid;
	pid = fork();
	if (pid == 0)
	{
		if (execute(line2, cont, v, t, n) == -1)
		{
			errors(cont, v, t, n);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		errors(cont, v, t, n);
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
