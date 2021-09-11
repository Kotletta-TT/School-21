#include "push_swap.h"

void	max_index_flag(t_lst *lst, t_main *info)
{
	int	res;

	res = 0;
	while (lst && !info->buf_flag)
	{
		if (lst->content.flag == info->flag)
			if (lst->content.index > res)
				res = lst->content.index;
		lst = lst->next;
	}
	while (lst && info->buf_flag)
	{
		if (lst->content.index > res)
			res = lst->content.index;
		lst = lst->next;
	}
	info->max = res;
}

int	count_move(t_lst *lst, int flag, t_main *info)
{
	int	res;

	res = 0;
	max_index_flag(lst, info);
	n_calc_midmax(info);
	while (lst)
	{
		if (flag == 1)
		{
			if (lst->content.index <= info->mid
				&& info->flag == lst->content.flag)
				res++;
		}
		else if (flag == 2)
		{
			if (lst->content.index > info->mid)
				res++;
		}
		lst = lst->next;
	}
	return (res);
}

int	start_move(int mv, t_lst **a, t_lst **b, t_main *info)
{
	int	len;

	len = 0;
	while (mv)
	{
		speed_two(a, info, &mv);
		if ((*a)->content.index <= info->mid && info->flag
			== (*a)->content.flag)
		{
			push(a, b, "pb\n", info);
			mv--;
		}
		else if ((*a)->content.index == info->next)
		{
			(*a)->content.flag = -1;
			rotate(a, 0, "ra\n", info);
			info->next += 1;
		}
		else
		{
			rotate(a, 0, "ra\n", info);
			len++;
		}
	}
	return (len);
}

void	speed_tree(t_lst **lst_a, t_lst **lst_b, t_main *info)
{
	if ((*lst_b)->content.index == info->next)
		reverse_rotate(lst_a, 0, "rra\n", info);
	else
		reverse_rotate(lst_a, lst_b, "rrr\n", info);
}

void	start_func(t_lst **lst_a, t_lst **lst_b, t_main *info, int flag)
{
	int	cnt_mv;
	int	len;

	info->buf_flag = 0;
	max_index_flag(*lst_a, info);
	n_calc_midmax(info);
	cnt_mv = count_move(*lst_a, flag, info);
	len = start_move(cnt_mv, lst_a, lst_b, info);
	while (len-- && !info->first)
		speed_tree(lst_a, lst_b, info);
}
