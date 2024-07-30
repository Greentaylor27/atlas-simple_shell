#include "main.h"
/**
 * main - runs program
 * @ac: number of arguements
 * @av: array holding arguements
 * Return: 0 on true and -1 on false
 */
int main(void)
{
	char *string = NULL;

	string = malloc(sizeof(char) * strlen(_path()));
	if (string == NULL)
	{
		free(string);
		printf("fail");
		return (-1);
	}
	string = strcpy(string, _path());
	printf("%s\n", string);
	free(string);
	return (1);
}
