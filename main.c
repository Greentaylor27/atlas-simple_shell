#include "main.h"
/**
 * main - runs program
 * @ac: number of arguements
 * @av: array holding arguements
 * Return: 0 on true and -1 on false
 */
int main(int ac, char **av)
{
	int number = 0;

	if ((number = interactive_mode(ac, av)) == -1)
		return (-1);
	return (1);
}
