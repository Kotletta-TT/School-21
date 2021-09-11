#include "mlx.h"
#include "so_long.h"
#include "stdlib.h"
#include "libft.h"

int	close_window(int key, t_game **game)
{
	(void) key;
	(void) game;
	exit(0);
}

void	run_game(t_map map)
{
	t_game	*game;

	game = malloc(sizeof(t_game) * 1);
	if (!game)
		ft_errors(1);
	game->map = &map;
	game->x_id = mlx_init();
	game->win = mlx_new_window(game->x_id,
			game->map->width * 30,
			game->map->height * 30, "so_long");
	game->cnt = get_cnt(map);
	game->cnt_mv = 0;
	build_map(&game);
	ft_putnbr_fd(game->cnt_mv, 1);
	ft_putchar_fd('\n', 1);
	mlx_key_hook(game->win, key_hook, &game);
	mlx_hook(game->win, 17, 131072L,
		close_window, &game);
	mlx_loop(game->x_id);
}

int	ft_lenarr(char **arr)
{
	int	key;

	key = 0;
	while (arr[key])
		key++;
	return (key);
}

void	check_extension(char *path, char *ext)
{
	int		k;
	char	**last_path;

	(void)ext;
	open_file(path);
	last_path = ft_split(path, '/');
	k = ft_lenarr(last_path);
	if (ft_strlen(last_path[k - 1]) <= (ft_strlen(ext)))
		ft_errors(1);
	path = last_path[k - 1];
	path += (ft_strlen(last_path[k - 1]) - (int)ft_strlen(ext));
	if (ft_strncmp(path, ext, (int)ft_strlen(ext)))
		ft_errors(1);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		exit(1);
	check_extension(argv[1], ".ber");
	map = parse_map(argv[1]);
	if (valid_map(map))
		run_game(map);
	exit(1);
}
