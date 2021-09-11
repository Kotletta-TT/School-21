#include "checker.h"
#include "get_next_line.h"
#include "libft.h"

int	valid_command(char *line)
{
	if (!ft_strncmp(line, "pa", ft_strlen("pa"))
		|| !ft_strncmp(line, "pb", ft_strlen("pb"))
		|| !ft_strncmp(line, "sa", ft_strlen("sa"))
		|| !ft_strncmp(line, "sb", ft_strlen("sb"))
		|| !ft_strncmp(line, "ss", ft_strlen("ss"))
		|| !ft_strncmp(line, "rra", ft_strlen("rra"))
		|| !ft_strncmp(line, "rrb", ft_strlen("rrb"))
		|| !ft_strncmp(line, "rrr", ft_strlen("rrr"))
		|| !ft_strncmp(line, "ra", ft_strlen("ra"))
		|| !ft_strncmp(line, "rb", ft_strlen("rb"))
		|| !ft_strncmp(line, "rr", ft_strlen("rr")))
		return (1);
	return (0);
}

void	apply_list(t_lst **a, t_lst **b, char *line)
{
	if (!ft_strncmp(line, "pa", ft_strlen("pa")))
		push(b, a, 0, 0);
	else if (!ft_strncmp(line, "pb", ft_strlen("pb")))
		push(a, b, 0, 0);
	else if (!ft_strncmp(line, "sa", ft_strlen("sa")))
		swap(a, 0, 0, 0);
	else if (!ft_strncmp(line, "sb", ft_strlen("sb")))
		swap(b, 0, 0, 0);
	else if (!ft_strncmp(line, "ss", ft_strlen("ss")))
		swap(a, b, 0, 0);
	else if (!ft_strncmp(line, "rra", ft_strlen("rra")))
		reverse_rotate(a, 0, 0, 0);
	else if (!ft_strncmp(line, "rrb", ft_strlen("rrb")))
		reverse_rotate(b, 0, 0, 0);
	else if (!ft_strncmp(line, "rrr", ft_strlen("rrr")))
		reverse_rotate(a, b, 0, 0);
	else if (!ft_strncmp(line, "ra", ft_strlen("ra")))
		rotate(a, 0, 0, 0);
	else if (!ft_strncmp(line, "rb", ft_strlen("rb")))
		rotate(b, 0, 0, 0);
	else if (!ft_strncmp(line, "rr", ft_strlen("rr")))
		rotate(a, b, 0, 0);
}

void	free_checker(t_lst **a, t_lst **b, char *line, int flag)
{
	if (*b)
		ft_lstcler(b);
	if (*b)
		ft_lstcler(a);
	if (line)
		free(line);
	if (flag)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	check_line(char **line, t_lst **a, t_lst **b)
{
	int	i;

	i = get_next_line(0, line);
	while (i)
	{
		if (valid_command(*line))
		{
			apply_list(a, b, *line);
			free(*line);
			i = get_next_line(0, line);
		}
		else
			free_checker(a, b, *line, 1);
	}
}

int	main(int argc, char **argv)
{
	t_lst	*lst;
	t_lst	*b_lst;
	char	*line;

	line = 0;
	argc --;
	b_lst = 0;
	argv++;
	if (!argc)
		return (0);
	lst = validate_input(argc, argv);
	check_line(&line, &lst, &b_lst);
	if (check_win(lst, b_lst))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_checker(&lst, &b_lst, line, 0);
}
