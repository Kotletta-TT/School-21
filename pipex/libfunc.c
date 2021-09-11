#include "pipex.h"

int		ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		arrlen(char **arr)
{
	int i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	*ft_strcpy(const char *src)
{
	int		i;
	char	*dest;

	if (!src)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

char	**arrcpy(char **src)
{
	int i;
	int len;
	char **dest;

	len = arrlen(src);
	if (!len)
		return (NULL);
	dest = malloc(sizeof(char *) * (len + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (src[++i])
	{
		dest[i] = ft_strcpy(src[i]);
		if (!dest[i])
			return (NULL);
	}
	dest[len] = NULL;
	return (dest);
}

int		ft_strcmpr(const char *s1, const char *s2, int length)
{
	int i;

	i = -1;
	while (++i < length)
		if (s1[i] == s2[i])
			continue ;
		else
			return (0);
		return (1);
}
