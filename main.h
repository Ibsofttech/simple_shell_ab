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

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

void signal_handler(int env);
void _env(char *line);
extern char **environ;
int my_exit(char *args);
int execmd(char *command, char **args);
char *get_location(char *command);
char **_strtok(char *input);
char *m_environ();
char *path_process(char *path, char *command);
void _write(char *str, int stm);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);
int _strlen(char *s);
char *str_cpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void free_args(char **args, int count);


#endif
