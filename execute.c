#include "main.h"

/**
 * execute - forks, executes and waits
 * @path: original path to executable
 * @getPath: path including command
 * @strArray: arguments
 *
 * Return: status of child process execution
 *         On success: 0
 *         On failure:
 *         2 - misuse of shell builtins
 *         126 - command not executable
 *         127 - command not found
 */
int execute(char *path, char *getPath, char **strArray)
{
	pid_t pid, signal;
	int status = 0;

	/* Frees path and begins the forking process */
	free(path);
	pid = fork();

	if (pid == 0)
	{
		/* char *envp[] = {NULL}; */
		/* Checks for an error */
		if (execve(getPath, strArray, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	exit(EXIT_FAILURE);
	else
	{
		/* Waits for the child process to complete and stores the status to status */
		do {
			signal = waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	(void)signal;
	return (status);
}
