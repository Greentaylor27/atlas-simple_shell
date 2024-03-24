#include "main.h"
/**
* main - infinite loop, and placeholder for frees and executions
*
* @argc: argument count (void)
* @argv: arguments (void)
* Return: exit status (should be 0)
*/

int main(int argc, char **argv)
{
	/* Setting Variables for shell */
	char *input = NULL, *path = NULL, *tokenArray[20], *pathArray[20];
	size_t size = 0;
	int status = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		/* Fetches the PATH enviornment variable and sets it to path */
		path = get_environ(environ);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Shell $ ", 8);
		/* If there is an error this block frees the memory */
		if (getline(&input, &size, stdin) == -1)
		{
			free(input);
			free(path);
			exit(EXIT_SUCCESS);
		}
		/* Tokenize the path at the : character */
		tokenize_string(path, ":", pathArray);
		/* Tokenize user input at the new line and at the tabs character */
		tokenize_string(input, " \n\t", tokenArray);
		/* If there is no user input frees path variable */
		if (!tokenArray[0])
		{
			free(path);
			continue;
		}
		/* Checks if the input is executeable if not calls the one_exit function */
		if (access(tokenArray[0], X_OK) == 0)
			execute(path, tokenArray[0], tokenArray);
		else
			status = check_path(path, pathArray, tokenArray);
		if (strcmp(tokenArray[0], "exit") == 0)
		{
			if (tokenArray[1] == NULL)
			one_exit(input, path);
		}
	}
	return (status);
}

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
