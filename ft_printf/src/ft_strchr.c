#include "../includes/ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	new_c;
	size_t	i;
	size_t	c_s;

	i = 0;
	c_s = ft_strlen(s) + 1;
	new_c = (char) c;
	while (i < c_s)
	{
		if (s[i] == new_c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
