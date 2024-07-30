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

	string = malloc(sizeof(char) * strlen(_path()));/*sets up a string to hold path*/
	if (string == NULL)
	{
		free(string);
		printf("fail");
		return (-1);
	}
	string = strcpy(string, _path());
	token = strtok(string, ":=");/*point a pointer to the token*/
	while (token != NULL)
	{
		catch = malloc(sizeof(char) * strlen(token) + strlen(buffer) + 2);/*copy the the token to a different string to concatenate file path*/
		catch = strcpy(catch, token);
		catch = strcat(catch, "/");
		catch = strcat(catch, buffer);
		if (stat(catch, &st) == 0)/*if valid runs a command and exits*/
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
		free(catch);
		token = strtok(NULL, ":=");
	}
	free(string);
	return (-1);
}