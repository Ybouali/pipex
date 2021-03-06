#include "../includes/pipex.h"

static char *ft_get_cmd(char **paths, char *cmd)
{
    char *tmp;
    char *command;

    while (*paths)
    {
        tmp = ft_strjoin(*paths, "/");
        command = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(command, 0) == 0)
            return (command);
        free(command);
        paths++;
    }
    return (NULL);
}

void ft_child_1(t_pipex pipex, char **av, char **en)
{
    dup2(pipex.tube[1], 1);
    close(pipex.tube[0]);
    dup2(pipex.infile, 0);
    pipex.cmd_args = ft_split(av[2], ' ');
    pipex.cmd = ft_get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
    if (!pipex.cmd)
    {
        ft_free_child(&pipex);
        ft_putendl_fd("Command not found :)", 2);
        exit(1);
    }
    execve(pipex.cmd, pipex.cmd_args, en);
}

void ft_child_2(t_pipex pipex, char **av, char **en)
{
    dup2(pipex.tube[0], 0);
    close(pipex.tube[1]);
    dup2(pipex.outfile, 1);

    pipex.cmd_args = ft_split(av[3], ' ');
    pipex.cmd = ft_get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
    if (!pipex.cmd)
    {
        ft_free_child(&pipex);
        ft_putendl_fd("Command not found :)", 2);
        exit(1);
    }
    execve(pipex.cmd, pipex.cmd_args, en);
}