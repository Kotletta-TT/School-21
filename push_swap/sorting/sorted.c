#include "push_swap.h"
#include "libft.h"

int	check_win(t_lst *a_lst, t_lst *b_lst)
{
	if (b_lst)
		return (0);
	while (a_lst && a_lst->next)
	{
		if (a_lst->content.index > a_lst->next->content.index)
			return (0);
		a_lst = a_lst->next;
	}
	return (1);
}

void	big_algoritm(t_lst **a_lst, t_lst **b_lst, t_main *info)
{
	while (!check_win(*a_lst, *b_lst))
	{
		start_func(a_lst, b_lst, info, 1);
		clean_b(a_lst, b_lst, info);
		first_order(b_lst, a_lst, info);
		info->first = 0;
		max_index_flag(*a_lst, info);
		n_calc_midmax(info);
		push_flag(a_lst, b_lst, info);
		calc_midmax(info);
		clean_b(a_lst, b_lst, info);
		first_order(b_lst, a_lst, info);
	}
}

void	clear_tool(t_list **list)
{
	t_list	*tmp;

	tmp = (*list)->next->next->next;
	free((*list)->next->next);
	free((*list)->next);
	(*list)->next = tmp;
}

void	clear_log(t_list **list)
{
	t_list	*m_list;

	m_list = *list;
	if (!m_list || !m_list->next)
		return ;
	while (m_list->next->next)
	{
		if ((!ft_strncmp(m_list->next->content, "pb\n", ft_strlen("pb\n"))
				&& !ft_strncmp(m_list->next->next->content, "pa\n",
					ft_strlen("pa\n"))))
			clear_tool(&m_list);
		if ((!ft_strncmp(m_list->next->content, "pa\n", ft_strlen("pa\n"))
				&& !ft_strncmp(m_list->next->next->content, "pb\n",
					ft_strlen("pb\n"))))
			clear_tool(&m_list);
		m_list = m_list->next;
	}
}

void	ft_sorted(t_lst *lst)
{
	t_main	*info;
	t_lst	*b_lst;

	b_lst = 0;
	info = init_info_struct(len_lst(lst));
	if (len_lst(lst) > 5)
	{
		big_algoritm(&lst, &b_lst, info);
		clear_log(&info->log_str);
	}
	else if (len_lst(lst) < 6 && len_lst(lst) > 1)
		if (!check_win(lst, b_lst))
			small_algoritm(&lst, &b_lst, info);
	print_list(info->log_str);
	ft_lstclear_new(&info->log_str);
	free(info);
	ft_lstcler(&lst);
}
