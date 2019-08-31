#include "shell.h"
/**
 * execute_command - exe.
 * @cont: number of commands.
 * @v: command.
 * @t: error of the command.
 * @n: name of the exe.
 * @args: aguments of the command.
 * @p: line of command.
 * Return: an integer.
**/
int execute_command(char **args, char *p, int cont, char *v, char *t, char *n)
{
	pid_t pid, wpid;
	int status;
	char us[128] = "/bin", *aux = "/b";
	(void)wpid;

	if (p[0] == aux[0] && p[1] == aux[1])
	{
		_strcpy(us, p);
	}
	else
	{
		_strcat(us, "/");
		_strcat(us, p);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(us, args, NULL) == -1)
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
