#include "push_swap.h"

void	mid_func(t_lst **lst_b, t_lst **lst_a, t_main *info, int flag)
{
	int	cnt_mv;

	info->buf_flag = 1;
	cnt_mv = count_move(*lst_b, flag, info);
	info->flag += 1;
	while (cnt_mv)
	{
		if ((*lst_b)->content.index > info->mid)
		{
			(*lst_b)->content.flag = info->flag;
			push(lst_b, lst_a, "pa\n", info);
			cnt_mv--;
		}
		else if ((*lst_b)->content.index == info->next)
		{
			push(lst_b, lst_a, "pa\n", info);
			(*lst_a)->content.flag = -1;
			rotate(lst_a, 0, "ra\n", info);
			info->next += 1;
		}
		else
			rotate(lst_b, 0, "rb\n", info);
	}
}

void	clean_b(t_lst **a_lst, t_lst **b_lst, t_main *info)
{
	while (len_lst(*b_lst) > 3)
	{
		calc_midmax(info);
		mid_func(b_lst, a_lst, info, 2);
	}
}

int	check_empty_flag(t_lst *lst, t_main *info)
{
	if (info->flag == 0)
		return (0);
	while (lst)
	{
		if (lst->content.flag == info->flag)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	first_order(t_lst **b_lst, t_lst **a_lst, t_main *info)
{
	while (*b_lst)
	{
		if ((*b_lst)->next && ((*b_lst)->next->content.index == info->next))
			swap(b_lst, 0, "sb\n", info);
		push(b_lst, a_lst, "pa\n", info);
		while ((*a_lst)->content.index == info->next)
		{
			if ((*a_lst)->content.index == info->next)
			{
				(*a_lst)->content.flag = -1;
				rotate(a_lst, 0, "ra\n", info);
				info->next += 1;
			}
			while (check_empty_flag(*a_lst, info))
				info->flag -= 1;
		}
	}
}

void	push_flag(t_lst **a_lst, t_lst **b_lst, t_main *info)
{
	speed_start_a(a_lst, info);
	while (check_empty_flag(*a_lst, info))
		info->flag -= 1;
	while ((info->flag == (*a_lst)->content.flag) && info->flag != 0)
		push(a_lst, b_lst, "pb\n", info);
}
