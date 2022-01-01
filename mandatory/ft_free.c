#include "../includes/pipex.h"

void ft_free_child(t_pipex *pipex)
{
    int i;

    i = -1;
    while (pipex->cmd_args[++i])
        free(pipex->cmd_args[i]);
    free(pipex->cmd_args);
    free(pipex->cmd);
}

void ft_free_parent(t_pipex *pipex)
{
    int i;

    i = -1;
    close(pipex->infile);
    close(pipex->outfile);
    while (pipex->cmd_paths[++i])
        free(pipex->cmd_paths[i]);
    free(pipex->cmd_paths);
}