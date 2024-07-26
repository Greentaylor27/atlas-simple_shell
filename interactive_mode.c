#include "main.h"
/**
 * interactive_mode - main running method of shell
 * Return: 1 on true -1 on fail
 */
int interactive_mode(int ac, char **av)
{
	char *buffer = NULL, *path, *exe;
	size_t size = 0, coms;
	ssize_t count = 0;
	struct stat st;

	(void)ac;
	(void)av;
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
		path = strtok(_path(), ":=");
		while (path != NULL)
		{
			exe = malloc(sizeof(char) * strlen(path) + 3);
			for (coms = 0; coms < strlen(path); coms++)
				exe[coms] = path[coms];
			exe[coms] = '/';
			for (coms = 0; coms < 2; coms++)
				exe[coms + strlen(path) + 1] = buffer[coms];
			if ((stat(exe, &st)) == 0)
				execve(exe, av, environ);
			path = strtok(NULL, ":=");
		}
	}
	return (1);
}