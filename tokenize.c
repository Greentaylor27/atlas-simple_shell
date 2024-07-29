#include "main.h"

/**
 * tokenize - Function to tokenize
 * @str: String being tokenized
 * @delim: where to tokenize the string
 * 
 * Return: a pointer to an array of strings or NULL on failure
 */

char **tokenize(const char *str, char *delim)
{
	int size = 64;
	int i = 0;
	char **tokenArr = malloc(size * sizeof(char *));
	char *token = NULL;
	char *newStr = NULL;

	if ((newStr = strdup(str)) == NULL)
	{
		perror("Memory allocation failed for newStr");
	}

	token = strtok(newStr, delim);
	while (token != NULL) {
		tokenArr[i] = token;
	}
	tokenArr[i] = NULL;

	for(; tokenArr[i] != NULL; i++)
		tokenArr[i] = NULL;

	free(tokenArr);

	return (tokenArr);
}
