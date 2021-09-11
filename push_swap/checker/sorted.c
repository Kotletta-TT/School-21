#include "checker.h"
#include "libft.h"

int	check_win(t_lst *a_lst, t_lst *b_lst)
{
	if (b_lst || !a_lst)
		return (0);
	while (a_lst && a_lst->next)
	{
		if (a_lst->content.index > a_lst->next->content.index)
			return (0);
		a_lst = a_lst->next;
	}
	return (1);
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
