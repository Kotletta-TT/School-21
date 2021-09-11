#include "get_next_line.h"
#include "libft.h"
#include "so_long.h"

int	get_height(t_map map)
{
	int	res;

	res = 0;
	while (map.map[res])
		res++;
	return (res);
}

int	get_width(t_map map)
{
	int	res;
	int	i;

	i = 0;
	res = (int)ft_strlen(map.map[i]);
	while (map.map[i])
		if (res != (int)ft_strlen(map.map[i++]))
			ft_errors(1);
	return (res);
}

void	check_min_map(t_map map)
{
	if ((map.width < 3 && map.height < 5) || (map.width < 5 && map.height < 3))
		ft_errors(1);
}

void	check_conture(t_map map)
{
	int	i;
	int	k;

	i = -1;
	while (map.map[++i])
		if ((int)ft_strlen(map.map[i]) != map.width)
			ft_errors(1);
	k = -1;
	while (map.map[0][++k])
		if (map.map[0][k] != '1')
			ft_errors(1);
	k = -1;
	while (map.map[map.height - 1][++k])
		if (map.map[map.height - 1][k] != '1')
			ft_errors(1);
	i = -1;
	while (map.map[++i])
		if (map.map[i][0] != '1' || map.map[i][map.width - 1] != '1')
			ft_errors(1);
}

int	valid_map(t_map map)
{
	check_symbol(map);
	check_min_map(map);
	check_conture(map);
	return (1);
}
