#include "../includes/pipex.h"

static void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void ft_putstr_fd(char *s, int fd)
{
	int index;

	if (s == NULL)
		return;
	index = 0;
	while (s[index])
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
}

void ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
