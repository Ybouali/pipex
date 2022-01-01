#include "../includes/pipex.h"

static void *ft_memset(void *b, int c, size_t len)
{
	while (len--)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}

static void ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void *ft_calloc(size_t count, size_t size)
{
	void *ret;

	ret = (void *)malloc(size * count);
	if (!ret)
		return (NULL);
	ft_bzero(ret, count * size);
	return (ret);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	index = 0;
	while (index < n && a[index] && b[index])
	{
		if (a[index] == b[index])
			index++;
		else
			return (a[index] - b[index]);
	}
	if (index == n)
		return (0);
	return (a[index] - b[index]);
}
