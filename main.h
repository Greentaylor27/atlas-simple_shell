#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/* Macros */
#define ERROR -1
#define PROMPT "SimpleShell$"
/* Environ */
extern char **environ;

/* Functions */
char *_path(void);
char *read_input(void);
int interactive_mode(int ac, char **av);

#endif
