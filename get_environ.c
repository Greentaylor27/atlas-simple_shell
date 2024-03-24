#include "main.h"
/**
* *get_environ - gets the environment variable, excluding "PATH="
*
* @environ: environment variable, globally declared in main.h
* Return: path, excluding "PATH="
*/
char *get_environ(char **environ)
{
	int i = 0;
	char *path = NULL;

	while (environ[i] != NULL)
	{
		/* Checks if environ is equal to PATH= */
	if (strncmp(environ[i], "PATH=", 5) == 0)
	{
		/* Copies path starting at the sixth character in PATH= string */
		size_t length = strlen(environ[i]) - 5;
		path = (char *)malloc((length + 1) * sizeof(char));
		if (path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		strncpy(path, environ[i] + 5, length);
		path[length] = '\0'
		break;
	}
	i++;
	}
	return (path);
}
