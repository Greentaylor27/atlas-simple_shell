#include "main.h"
/**
 * _path - returns the path of a command
 * @string: environment to find a path
 * Return: returns path or NULL on fail
 */
char *_path(void)
{
	int number = 0;

	for (; environ[number] != NULL; number++)
	{
		if (strncmp(environ[number], "PATH=", 5) == 0)/*searches through environment for path*/
			return (environ[number]);
	}
	return (NULL);
}
