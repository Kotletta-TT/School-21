#include "so_long.h"
#include "libft.h"
void	draw_map(t_game **game)
{
	int		i;
	int		k;

	i = 0;
	while ((*game)->map->map[i])
	{
		k = 0;
		while ((*game)->map->map[i][k])
		{
			if ((*game)->map->map[i][k] == '1')
				build_wall((*game), i, k);
			else if ((*game)->map->map[i][k] == '0')
				build_bg((*game), i, k);
			else if ((*game)->map->map[i][k] == 'P')
				build_player((*game), i, k);
			else if ((*game)->map->map[i][k] == 'E')
				build_exit((*game), i, k);
			else if ((*game)->map->map[i][k] == 'C')
				build_money((*game), i, k);
			k++;
		}
		i++;
	}
}

void	move_up(t_game **game)
{
	int		x;
	int		y;

	get_cur_pos(game);
	x = (*game)->plr_pos.x;
	y = (*game)->plr_pos.y;
	if ((*game)->map->map[y - 1][x] == '1')
		return ;
	else if ((*game)->map->map[y - 1][x] == '0'
	|| (*game)->map->map[y - 1][x] == 'C')
	{
		if ((*game)->map->map[y - 1][x] == 'C')
			(*game)->cnt -= 1;
		(*game)->plr_pos.y -= 1;
		(*game)->map->map[y][x] = '0';
		(*game)->map->map[y - 1][x] = 'P';
		(*game)->cnt_mv += 1;
		ft_putnbr_fd((*game)->cnt_mv, 1);
		ft_putchar_fd('\n', 1);
		draw_map(game);
		return ;
	}
	else if ((*game)->map->map[y - 1][x] == 'E')
		if (!(*game)->cnt)
			ft_errors(10);
}

void	move_down(t_game **game)
{
	int		x;
	int		y;

	get_cur_pos(game);
	x = (*game)->plr_pos.x;
	y = (*game)->plr_pos.y;
	if ((*game)->map->map[y + 1][x] == '1')
		return ;
	else if ((*game)->map->map[y + 1][x] == '0'
	|| (*game)->map->map[y + 1][x] == 'C')
	{
		if ((*game)->map->map[y + 1][x] == 'C')
			(*game)->cnt -= 1;
		(*game)->plr_pos.y -= 1;
		(*game)->map->map[y][x] = '0';
		(*game)->map->map[y + 1][x] = 'P';
		(*game)->cnt_mv += 1;
		ft_putnbr_fd((*game)->cnt_mv, 1);
		ft_putchar_fd('\n', 1);
		draw_map(game);
		return ;
	}
	else if ((*game)->map->map[y + 1][x] == 'E')
		if (!(*game)->cnt)
			ft_errors(10);
}

void	move_left(t_game **game)
{
	int		x;
	int		y;

	get_cur_pos(game);
	x = (*game)->plr_pos.x;
	y = (*game)->plr_pos.y;
	if ((*game)->map->map[y][x - 1] == '1')
		return ;
	else if ((*game)->map->map[y][x - 1] == '0' || (*game)->map->map[y][x - 1]
												   == 'C')
	{
		if ((*game)->map->map[y][x - 1] == 'C')
			(*game)->cnt -= 1;
		(*game)->plr_pos.y -= 1;
		(*game)->map->map[y][x] = '0';
		(*game)->map->map[y][x - 1] = 'P';
		(*game)->cnt_mv += 1;
		ft_putnbr_fd((*game)->cnt_mv, 1);
		ft_putchar_fd('\n', 1);
		draw_map(game);
		return ;
	}
	else if ((*game)->map->map[y][x - 1] == 'E')
		if (!(*game)->cnt)
			ft_errors(10);
}

void	move_right(t_game **game)
{
	int		x;
	int		y;

	get_cur_pos(game);
	x = (*game)->plr_pos.x;
	y = (*game)->plr_pos.y;
	if ((*game)->map->map[y][x + 1] == '1')
		return ;
	else if ((*game)->map->map[y][x + 1] == '0' || (*game)->map->map[y][x + 1]
												   == 'C')
	{
		if ((*game)->map->map[y][x + 1] == 'C')
			(*game)->cnt -= 1;
		(*game)->plr_pos.y -= 1;
		(*game)->map->map[y][x] = '0';
		(*game)->map->map[y][x + 1] = 'P';
		(*game)->cnt_mv += 1;
		ft_putnbr_fd((*game)->cnt_mv, 1);
		ft_putchar_fd('\n', 1);
		draw_map(game);
		return ;
	}
	else if ((*game)->map->map[y][x + 1] == 'E')
		if (!(*game)->cnt)
			ft_errors(10);
}
