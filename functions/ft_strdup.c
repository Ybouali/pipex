#include "../includes/pipex.h"

size_t ft_strlen(const char *s)
{
	size_t index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

static size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t index;

	index = 0;
	if (dstsize > 0)
	{
		while (src[index] && index + 1 < dstsize)
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	index = ft_strlen(src);
	return (index);
}

char *ft_strdup(const char *s1)
{
	char *buff;
	int len;

	buff = (void *)0;
	len = ft_strlen(s1);
	buff = (char *)ft_calloc(len + 1, sizeof(char));
	if (!buff)
		return (buff);
	ft_strlcpy(buff, s1, len + 1);
	return (buff);
}
