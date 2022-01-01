#ifndef PIPEX_H
#define PIPEX_H

// include libery

#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

// for perror
#include <stdio.h>
// struct that hold information

typedef struct s_pipex
{
    pid_t pid1;
    pid_t pid2;
    int tube[2];
    int infile;
    int outfile;
    char *paths;
    char **cmd_paths;
    char **cmd_args;
    char *cmd;
} t_pipex;

// childs
void ft_child_1(t_pipex pipex, char **av, char **en);
void ft_child_2(t_pipex pipex, char **av, char **en);

// free pipex functions
void ft_free_child(t_pipex *pipex);
void ft_free_parent(t_pipex *pipex);

// functions

void *ft_calloc(size_t count, size_t size);
char **ft_split(const char *str, char c);
size_t ft_strlen(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strjoin(char const *s1, char const *s2);
void ft_putendl_fd(char *s, int fd);

#endif
