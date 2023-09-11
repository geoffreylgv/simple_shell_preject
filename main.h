#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

int _putchar(char c);
int print_string(char *str);
void handle_ctrld(ssize_t value, char **lineptr);
char *path(char *rep, char *command);
char **token_string(char *command);
char *get_envpath(void);
int launch_one(char **args, char **argv, char *getcmd);
int launch_two(char **args, char **argv);

#endif
