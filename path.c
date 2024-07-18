#include "main.h"
/**
 * _path - returns the path of a command
 * @string: environment to find a path
 * Return: returns path or NULL on fail
 */
char *_path(char *env)
{
	char *path = NULL;
	int number = 0;

	while (env[number] != '\0')
		number++;
	path = malloc(sizeof(char) * number);
	if (path == NULL)
	{
		free(path);
		return (0);
	}
	path = strtok(env, "\n");
	while(strtok(NULL, "\n"))
	{
		path = strtok(NULL, "\n");
		if (strcmp(path, "PATH=", 5))
			return (path);
	}
	free(path);
	return (NULL);
}
