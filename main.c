#include "main.h"
/**
 * main - runs program
 * @ac: number of arguements
 * @av: array holding arguements
 * Return: 0 on true and -1 on false
 */
int main(int ac, char **av)
{
	char *string = _path(), *str;
	struct stat *name;

	if (ac < 3)
	{
		name = malloc(sizeof(struct stat));
		if (name == NULL)
		{
			free(name);
			return (-1);
		}
		str = malloc(sizeof(char) * 1024);
		if (str == NULL)
		{
			free(name);
			free(str);
			return (-1);
		}
		str = strtok(string, ":");
		while (str != NULL)
		{
			if (stat(str, name) == 0)
			{
				str = strcat(str, "/");
				execve(str, av, environ);
				break;
			}
			str = strtok(NULL, ":");
		}
		printf("Didn't work\n");
	}
	printf("Nothing happend\n");
	return (1);
}