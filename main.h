#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Macros */
#define ERROR -1

/* Environ */
extern char **environ;

/* Functions */
char *_path(void);
char *read_input(void);

#endif
