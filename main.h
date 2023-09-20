#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

void signal_handler(int env);
void _env(char *line);
extern char **environ;
int my_exit(char *args);
int execmd(char *command, char **args);
char *get_location(char *command);
char **_strtok(char *input);
char *m_environ();
char *path_process(char *path, char *command);

#endif