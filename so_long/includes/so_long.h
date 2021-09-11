#ifndef SO_LONG_H
# define SO_LONG_H
typedef struct s_map
{
	char	**map;
	int		cnt;
	int		height;
	int		width;
	int		cnt_p;
	int		cnt_e;
	int		cnt_c;
}				t_map;
typedef struct s_img
{
	void	*img;
	char	*path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;
typedef struct s_plr_pos
{
	int	x;
	int	y;
}				t_plr_pos;
typedef struct s_game
{
	t_plr_pos	plr_pos;
	t_img		player;
	t_img		wall;
	t_img		exit;
	t_img		money;
	t_img		bg;
	t_map		*map;
	void		*x_id;
	void		*win;
	int			cnt;
	int			cnt_mv;
}				t_game;
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define SYMBOL_MAP "01CPE"
void	ft_errors(int err);
t_map	parse_map(char *path);
int		valid_map(t_map map);
void	load_textures(t_game *game);
void	build_map(t_game **game);
int		get_cnt(t_map map);
int		key_hook(int key, t_game **game);
void	get_cur_pos(t_game **game);
void	draw_map(t_game **game);
void	move_up(t_game **game);
void	move_down(t_game **game);
void	move_left(t_game **game);
void	move_right(t_game **game);
int		close_window(int key, t_game **game);
void	run_game(t_map map);
void	load_bg(t_game *game);
void	load_wall(t_game *game);
void	load_player(t_game *game);
void	load_money(t_game *game);
void	load_exit(t_game *game);
void	build_wall(t_game *game, int i, int k);
void	build_bg(t_game *game, int i, int k);
void	build_player(t_game *game, int i, int k);
void	build_money(t_game *game, int i, int k);
void	build_exit(t_game *game, int i, int k);
int		get_height(t_map map);
int		get_width(t_map map);
void	check_min_map(t_map map);
void	check_conture(t_map map);
int		open_file(char *path);
int		count_str(char *path);
void	check_symbol(t_map map);
#endif
