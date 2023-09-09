#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int _putchar(char c);
int print_string(char *str);
void handle_ctrld(ssize_t value, char **lineptr);

#endif
