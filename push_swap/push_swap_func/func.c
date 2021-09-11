#include "push_swap.h"
#include "libft.h"

void	add_log(char *str, t_main *info)
{
	if (info && !info->log_str)
		info->log_str = ft_lstnew(str);
	else if (info && info->log_str)
		ft_lstadd_back(&info->log_str, ft_lstnew(str));
}

void	swap(t_lst **lst, t_lst **buf, char *s, t_main *info)
{
	t_lst	*tmp;

	if (lst && buf)
	{
		swap(lst, 0, 0, 0);
		swap(buf, 0, 0, 0);
		add_log(s, info);
		return ;
	}
	if (*lst && (*lst)->next)
	{
		tmp = (*lst)->next;
		(*lst)->next = tmp->next;
		tmp->next = *lst;
		*lst = tmp;
		add_log(s, info);
	}
}

void	push(t_lst **from, t_lst **to, char *s, t_main *info)
{
	t_lst	*tmp;
	t_lst	*tmp_to;

	if (*from)
	{
		tmp = (*from)->next;
		tmp_to = *to;
		*to = *from;
		(*to)->next = tmp_to;
		*from = tmp;
		add_log(s, info);
	}
}

void	rotate(t_lst **lst, t_lst **buf, char *s, t_main *info)
{
	t_lst	*tmp;
	t_lst	*last;

	if (lst && buf)
	{
		rotate(lst, 0, 0, 0);
		rotate(buf, 0, 0, 0);
		add_log(s, info);
		return ;
	}
	if (!(*lst) || !(*lst)->next)
		return ;
	last = lst_last(*lst);
	last->next = *lst;
	tmp = (*lst)->next;
	last->next->next = NULL;
	*lst = tmp;
	add_log(s, info);
}

void	reverse_rotate(t_lst **lst, t_lst **buf, char *s, t_main *info)
{
	t_lst	*tmp;
	t_lst	*llst;

	if (lst && buf)
	{
		reverse_rotate(lst, 0, 0, 0);
		reverse_rotate(buf, 0, 0, 0);
		add_log(s, info);
		return ;
	}
	llst = *lst;
	if (!llst || !llst->next)
		return ;
	while (llst->next->next)
		llst = llst->next;
	tmp = llst->next;
	llst->next = NULL;
	tmp->next = *lst;
	*lst = tmp;
	add_log(s, info);
}
