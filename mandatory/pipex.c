#include "../includes/pipex.h"

char *ft_find_path(char **en)
{
    while (ft_strncmp("PATH", *en, 4))
        en++;
    return (*en + 5);
}

static void ft_msg_error(char *msg)
{
    perror(msg);
    exit(1);
}

static void ft_close(t_pipex *pipex)
{
    close(pipex->tube[0]);
    close(pipex->tube[1]);
}

int main(int ac, char **av, char **en)
{
    t_pipex pipex;

    if (ac != 5)
    {
        ft_putendl_fd("Invalide numbers of argements :)", 2);
        return (0);
    }
    pipex.infile = open(av[1], O_RDONLY);
    if (pipex.infile == -1)
        ft_msg_error("Infile");
    pipex.outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
    if (pipex.outfile == -1)
        ft_msg_error("Outfile");
    if (pipe(pipex.tube) == -1)
        ft_msg_error("Pipe");
    pipex.paths = ft_find_path(en);
    pipex.cmd_paths = ft_split(pipex.paths, ':');
    pipex.pid1 = fork();
    if (pipex.pid1 == 0)
        ft_child_1(pipex, av, en);
    pipex.pid2 = fork();
    if (pipex.pid2 == 0)
        ft_child_2(pipex, av, en);
    ft_close(&pipex);
    waitpid(pipex.pid1, NULL, 0);
    waitpid(pipex.pid2, NULL, 0);
    ft_free_parent(&pipex);
}