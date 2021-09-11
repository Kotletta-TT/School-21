#include "push_swap.h"
#include "libft.h"

int	is_int(char *str)
{
	char		*tmp;
	long long	i;
	int			k;

	k = -1;
	tmp = str;
	while (str[++k])
		if ((!ft_isdigit(str[k])) && str[k] != 45 && str[k] != 43)
			return (0);
	i = ft_atoi(tmp);
	if (i > INT_MAX || i < INT_MIN)
		return (0);
	return (1);
}

int	is_normal_format(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45 || *str == 43)
		str++;
	while (*str >= 48 && *str <= 57)
		str++;
	if (*str)
		return (0);
	return (1);
}

void	validate_args(char **splt)
{
	long long	i;

	i = -1;
	while (splt[++i])
	{
		if (!is_normal_format(splt[i]) || !is_int(splt[i]))
			ft_error(splt, 0, 0);
	}
}

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	if (arr)
		while (arr[i])
			i++;
	return (i);
}

char	**add_to_arr(char **s1, char **s2)
{
	char	**res;
	int		i;
	int		k;

	res = malloc(sizeof(char *) * (ft_arrlen(s1) + ft_arrlen(s2)) + 1);
	if (!res)
		return (0);
	i = 0;
	if (ft_arrlen(s1))
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	k = 0;
	while (s2[k])
		res[i++] = s2[k++];
	res[i] = 0;
	free(s1);
	free(s2);
	return (res);
}
