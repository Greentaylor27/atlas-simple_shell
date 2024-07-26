#include "main.h"

/**
	* read_input - Returns a string to be tokenized
	*
	* Return: Buffer
*/

char *read_input(void)
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&buffer, &len, stdin);
	if (read == ERROR)
	{
		printf("Error reading input\n");
		return (NULL);
	}
	return (buffer);
}
