#include "get_next_line.h"
#include "libft.h"
#include "so_long.h"

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_errors(1);
	return (fd);
}

int	count_str(char *path)
{
	int		i;
	int		res;
	int		fd;
	char	*line;

	fd = open_file(path);
	res = 0;
	i = get_next_line(fd, &line);
	while (i)
	{
		free(line);
		i = get_next_line(fd, &line);
		res++;
	}
	res++;
	free(line);
	return (res);
}

t_map	parse_map(char *path)
{
	static t_map	map;
	int				fd;
	int				i;
	int				k;

	map.cnt = count_str(path);
	map.map = malloc(sizeof(char *) * (map.cnt + 1));
	if (!map.map)
		ft_errors(1);
	fd = open_file(path);
	k = 0;
	i = get_next_line(fd, &map.map[k]);
	if (i < 0)
		ft_errors(1);
	while (i)
	{
		i = get_next_line(fd, &map.map[++k]);
		if (i < 0)
			ft_errors(1);
	}
	map.map[++k] = 0;
	map.height = get_height(map);
	map.width = get_width(map);
	return (map);
}
