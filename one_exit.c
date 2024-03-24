#include "main.h"

/**
* one_exit - function to handle the freeing and exiting
*
* @input: input from getline (to free)
* @path: path to executable (to free)
* Return: void
*/

void one_exit(char *input, char *path)
{
	free(input);
	free(path);
	exit(EXIT_SUCCESS);
}

