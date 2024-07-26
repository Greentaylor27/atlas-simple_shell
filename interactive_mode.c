#include "main.h"
/**
 * interactive_mode - main running method of shell
 * Return: 1 on true -1 on fail
 */
int interactive_mode(void)
{
	char *buffer = NULL;
	size_t size = 0;
	ssize_t count = 0;

	while (1)
	{
		printf("Enter command >");
		count = getline(&buffer, &size, stdin);
		if (count == -1)
		{
			printf("buffer fail\n");
			free (buffer);
			return (-1);
		}
		printf("%s\n", buffer);
		free(buffer);
	}
	return (1);
}