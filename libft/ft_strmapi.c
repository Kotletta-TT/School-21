#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	c_res;
	size_t	i;
	char	*res;

	if (!s)
		return (0);
	c_res = ft_strlen(s);
	res = malloc(c_res + 1);
	if (!res)
		return (0);
	i = -1;
	while (s[++i])
		res[i] = f(i, s[i]);
	res[i] = 0;
	return (res);
}
