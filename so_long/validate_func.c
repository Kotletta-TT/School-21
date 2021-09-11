#include "libft.h"
#include "so_long.h"

void 	ft_errors(int err)
{
	if (err == 1)
		ft_putstr_fd("Error\n", 2);
	else if (err == 10)
		ft_putstr_fd("You win!\n", 1);
	exit(1);
}

int 	count_sim_in_str(const char *str, char c)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			res++;
		i++;
	}
	return (res);
}

void	check_one_symbol(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		map->cnt_p += count_sim_in_str(map->map[i], 'P');
		map->cnt_e += count_sim_in_str(map->map[i], 'E');
		map->cnt_c += count_sim_in_str(map->map[i], 'C');
		i++;
	}
	if (map->cnt_p != 1 || map->cnt_e != 1 || map->cnt_c < 1)
		ft_errors(1);
}

void	check_symbol(t_map map)
{
	int	i;
	int	k;

	i = 0;
	while (map.map[i])
	{
		k = 0;
		while (map.map[i][k])
		{
			if (!ft_strchr_one(SYMBOL_MAP, map.map[i][k]))
				ft_errors(1);
			k++;
		}
		i++;
	}
	check_one_symbol(&map);
}
