#include "main.h"
/**
 * interactive_mode - main running method of shell
 * Return: 1 on true -1 on fail
 */
int interactive_mode(int ac, char **av)
{
	char *buffer = NULL;
	size_t size = 0;
	ssize_t count = 0;
	struct stat st;
	int pid;

	(void)ac;
	while (1)
	{
		printf("Enter command >");
		count = getline(&buffer, &size, stdin);/*gets input and stores in buffer*/
		if (count == -1)
		{
			printf("buffer fail\n");
			free (buffer);
			return (-1);
		}
		buffer[count - 1] = '\0';
		if (strcmp(buffer, "exit") == 0)/*hard coded exit*/
			break;
		if (stat(buffer, &st) == 0)/*runs a program if file path recognized*/
		{
			pid = fork();
			if (pid == 0)
				execve(buffer, av, environ);
			wait(NULL);
		}
		else
		{
			if (fcheck(av, buffer) == -1)
				printf("Not a command\n");
		}
	}
	free(buffer);
	return (1);
}