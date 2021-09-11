#include "push_swap.h"

void	calc_midmax(t_main *info)
{
	info->max = info->mid;
	info->mid = (info->max + info->next) / 2;
}

void	n_calc_midmax(t_main *info)
{
	info->mid = (info->max + info->next) / 2;
}

void	speed_start_a(t_lst **a_lst, t_main *info)
{
	while (((*a_lst)->next->content.index == info->next
			|| (*a_lst)->content.index == info->next))
	{
		if ((*a_lst)->next->content.index == info->next)
		{
			if (lst_last(*a_lst)->content.index == info->next - 1)
			{
				swap(a_lst, 0, "sa\n", info);
				(*a_lst)->content.flag = -1;
				rotate(a_lst, 0, "ra\n", info);
				info->next += 1;
			}
		}
		else if ((*a_lst)->content.index == info->next)
		{
			if (lst_last(*a_lst)->content.index == info->next - 1)
			{
				(*a_lst)->content.flag = -1;
				rotate(a_lst, 0, "ra\n", info);
				info->next += 1;
			}
		}
	}
}

void	speed_two(t_lst **a, t_main *info, int *mv)

{
	t_lst	*last;

	last = lst_last(*a);
	if (((*a)->content.index == info->next && (*a)->content.index != 1)
		|| ((*a)->next->content.index == info->next
			&& (*a)->next->content.index != 1))
	{
		if ((last->content.index == (*a)->next->content.index - 1)
			&& last->content.flag == -1)
			swap(a, 0, "sa\n", info);
		if ((last->content.index == (*a)->content.index - 1)
			&& last->content.flag == -1)
		{
			(*a)->content.flag = -1;
			rotate(a, 0, "ra\n", info);
			info->next += 1;
			(*mv)--;
		}
	}
}

void	print_list(t_list *list)
{
	while (list)
	{
		ft_putstr_fd(list->content, 1);
		list = list->next;
	}
}
