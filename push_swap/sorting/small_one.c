#include "push_swap.h"

void	start_2(t_lst **a, t_main *info)
{
	if ((*a)->content.index != info->next)
		swap(a, 0, "sa\n", info);
}

void	start_3(t_lst **a, t_main *info)
{
	if ((*a)->content.index == info->next)
	{
		if ((*a)->next->content.index == info->next + 1)
			return ;
		else
			s_1(a, info);
	}
	else if ((*a)->next->content.index == info->next)
	{
		if ((*a)->content.index == info->next + 1)
			s_2(a, info);
		else
			s_3(a, info);
	}
	else
	{
		if ((*a)->content.index == info->next + 1)
			s_4(a, info);
		else
			s_5(a, info);
	}
}

void	start_4(t_lst **a, t_lst **b, t_main *info)
{
	while ((*a)->content.index != info->next)
		rotate(a, 0, "ra\n", info);
	if ((*a)->content.index == info->next)
		push(a, b, "pb\n", info);
	info->next += 1;
	start_3(a, info);
	push(b, a, "pa\n", info);
}

void	start_5(t_lst **a, t_lst **b, t_main *info)
{
	while ((*a)->content.index != info->next)
		rotate(a, 0, "ra\n", info);
	if ((*a)->content.index == info->next)
		push(a, b, "pb\n", info);
	info->next += 1;
	start_4(a, b, info);
	push(b, a, "pa\n", info);
}

void	small_algoritm(t_lst **a, t_lst **b, t_main *info)
{
	if (len_lst(*a) == 2)
		start_2(a, info);
	else if (len_lst(*a) == 3)
		start_3(a, info);
	else if (len_lst(*a) == 4)
		start_4(a, b, info);
	else
		start_5(a, b, info);
}
