#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	i = 0;
	new_s1 = (unsigned char *) s1;
	new_s2 = (unsigned char *) s2;
	while (i < n)
	{
		if (!new_s1[i] && !new_s2[i])
			return (0);
		if (new_s1[i] - new_s2[i])
			return (new_s1[i] - new_s2[i]);
		i++;
	}
	return (0);
}
