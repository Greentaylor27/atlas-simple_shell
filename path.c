#include "main.h"
/**
 * _path - returns the path of a command
 * @string: environment to find a path
 * Return: returns path or NULL on fail
 */
char *_path(void)
{
	int number = 0;
	char *string = malloc(sizeof(char) * 1024);

	for (; environ[number] != NULL; number++)
	{
		if (strncmp(environ[number], "PATH=", 5) == 0)
		{
			string = environ[number];
			return (string);
		}
	}
	return (0);
}
