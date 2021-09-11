#include "mlx.h"
#include "so_long.h"

void	build_wall(t_game *game, int i, int k)
{
	mlx_put_image_to_window(
		game->x_id,
		game->win,
		game->wall.img,
		k * 30, i * 30);
}

void	build_bg(t_game *game, int i, int k)
{
	mlx_put_image_to_window(game->x_id, game->win, game->bg.img,
		k * 30, i * 30);
}

void	build_player(t_game *game, int i, int k)
{
	mlx_put_image_to_window(game->x_id, game->win, game->player.img,
		k * 30, i * 30);
}

void	build_money(t_game *game, int i, int k)
{
	mlx_put_image_to_window(game->x_id, game->win, game->money.img,
		k * 30, i * 30);
}

void	build_exit(t_game *game, int i, int k)
{
	mlx_put_image_to_window(game->x_id, game->win, game->exit.img,
		k * 30, i * 30);
}
