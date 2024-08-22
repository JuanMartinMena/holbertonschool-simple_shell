#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(char **env);
int f_w_e(char *pathname, char *argv[], char *envp[]);
char *Recorrer_el_path(char *input);
char *_getenv(const char *name);
char **array_kingdom(char *line);
void *_perror(char *s, int counter, char *l);
void free_array(char** array);

extern char **environ;

#endif
