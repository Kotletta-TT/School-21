#include "push_swap.h"
#include "stdio.h"

int	*convert_si(char **str)
{
	int	*res;
	int	i;

	i = -1;
	res = malloc(sizeof(int) * ft_arrlen(str));
	if (!res)
		return (NULL);
	while (str[++i])
		res[i] = (int)ft_atoi(str[i]);
	ft_flash_arr(str);
	return (res);
}

void	check_double(int *arr, int len_arr)
{
	int	i;
	int	k;
	int	tmp_len;

	i = 0;
	while (len_arr--)
	{
		tmp_len = len_arr;
		k = i + 1;
		while (tmp_len--)
		{
			if (arr[i] == arr[k])
			{
				free(arr);
				ft_error(0, 0, 0);
			}
			k++;
		}
		i++;
	}
}

t_lst	*validate_input(int argc, char **argv)
{
	char	**splt;
	char	**str;
	int		*res;
	t_lst	*lst;

	str = 0;
	while (argc--)
	{
		splt = ft_split(*argv, ' ');
		if (!splt)
			ft_error(0, 0, 0);
		validate_args(splt);
		str = add_to_arr(str, splt);
		argv++;
	}
	argc = ft_arrlen(str);
	res = convert_si(str);
	check_double(res, argc);
	lst = init_lst(res, argc);
	ft_qsort(res, 0, argc - 1);
	init_index(lst, res, argc);
	free(res);
	return (lst);
}

int	ft_error(char **arr, char **arr2, t_lst **lst)
{
	if (!arr2)
		ft_flash_arr(arr);
	else
	{
		ft_flash_arr(arr);
		ft_flash_arr(arr2);
	}
	if (lst)
		ft_lstcler(lst);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_flash_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
		while (arr[i])
			free(arr[i++]);
	free(arr);
}
