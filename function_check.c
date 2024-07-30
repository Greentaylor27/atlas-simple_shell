#include "main.h"
/**
 * fcheck - checks the input for file path
 * @av: arguement vector
 * @buffer: string of input
 * Return: int check 1 or -1
 */
int fcheck(char **av, char *buffer)
{
	char *string = NULL, *token, *catch = NULL;
	struct stat st;
	int pid;

	string = malloc(sizeof(char) * strlen(_path()));
	if (string == NULL)
	{
		free(string);
		printf("fail");
		return (-1);
	}
	string = strcpy(string, _path());
	token = strtok(string, ":=");
	while (token != NULL)
	{
		catch = malloc(sizeof(char) * strlen(token) + strlen(buffer) + 2);
		catch = strcpy(catch, token);
		catch = strcat(catch, "/");
		catch = strcat(catch, buffer);
		if (stat(catch, &st) == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				free(string);
				execve(catch, av, environ);
			}
			wait(NULL);
			return (1);
		}
		token = strtok(NULL, ":=");
	}
	free(string);
	return (-1);
}