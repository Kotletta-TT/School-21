#include "so_long.h"
#include "stdlib.h"
#include "libft.h"

void	load_textures(t_game *game)
{
	game->bg.path = ft_strdup("textures/background.xpm");
	game->wall.path = ft_strdup("textures/wall.xpm");
	game->player.path = ft_strdup("textures/player.xpm");
	game->money.path = ft_strdup("textures/money.xpm");
	game->exit.path = ft_strdup("textures/exit.xpm");
	if (!game->bg.path || !game->wall.path || !game->player.path
		|| !game->exit.path || !game->money.path)
		ft_errors(1);
	load_bg(game);
	load_player(game);
	load_wall(game);
	load_money(game);
	load_exit(game);
}

void	build_map(t_game **game)
{
	int		i;
	int		k;

	i = 0;
	load_textures((*game));
	while ((*game)->map->map[i])
	{
		k = 0;
		while ((*game)->map->map[i][k])
		{
			if ((*game)->map->map[i][k] == '1')
				build_wall(*game, i, k);
			else if ((*game)->map->map[i][k] == '0')
				build_bg(*game, i, k);
			else if ((*game)->map->map[i][k] == 'P')
				build_player(*game, i, k);
			else if ((*game)->map->map[i][k] == 'E')
				build_exit(*game, i, k);
			else if ((*game)->map->map[i][k] == 'C')
				build_money(*game, i, k);
			k++;
		}
		i++;
	}
}

int	get_cnt(t_map map)
{
	int	res;
	int	i;
	int	k;

	res = 0;
	i = 0;
	while (map.map[i])
	{
		k = 0;
		while (map.map[i][k])
		{
			if (map.map[i][k] == 'C')
				res++;
			k++;
		}
		i++;
	}
	return (res);
}

int	key_hook(int key, t_game **game)
{
	(void)game;
	if (key == ESC)
		exit(0);
	else if (key == W)
		move_up(game);
	else if (key == S)
		move_down(game);
	else if (key == A)
		move_left(game);
	else if (key == D)
		move_right(game);
	return (0);
}

void	get_cur_pos(t_game **game)
{
	int	i;
	int	k;

	i = 0;
	while ((*game)->map->map[i])
	{
		k = 0;
		while ((*game)->map->map[i][k])
		{
			if ((*game)->map->map[i][k] == 'P')
			{
				(*game)->plr_pos.x = k;
				(*game)->plr_pos.y = i;
				return ;
			}
			k++;
		}
		i++;
	}
}
