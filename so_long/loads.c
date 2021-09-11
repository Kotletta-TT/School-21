#include "mlx.h"
#include "so_long.h"

void	load_bg(t_game *game)
{
	game->bg.img = mlx_xpm_file_to_image(game->x_id, game->bg.path,
			&game->map->width, &game->map->height);
	if (!game->bg.img)
		ft_errors(1);
}

void	load_player(t_game *game)
{
	game->player.img = mlx_xpm_file_to_image(game->x_id, game->player.path,
			&game->map->width, &game->map->height);
	if (!game->player.img)
		ft_errors(1);
}

void	load_wall(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->x_id, game->wall.path,
			&game->map->width, &game->map->height);
	if (!game->wall.img)
		ft_errors(1);
}

void	load_money(t_game *game)
{
	game->money.img = mlx_xpm_file_to_image(game->x_id, game->money.path,
			&game->map->width, &game->map->height);
	if (!game->money.img)
		ft_errors(1);
}

void	load_exit(t_game *game)
{
	game->exit.img = mlx_xpm_file_to_image(game->x_id, game->exit.path,
			&game->map->width, &game->map->height);
	if (!game->exit.img)
		ft_errors(1);
}
