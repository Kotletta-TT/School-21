#include "libft.h"

void	ft_lstclear_new(t_list **lst)
{
	t_list	*buf;

	if (!*lst)
		return ;
	while ((*lst)->next)
	{
		buf = *lst;
		*lst = buf->next;
		free(buf);
	}
	free(*lst);
	*lst = 0;
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buf;

	if (!lst || !del)
		return ;
	while ((*lst)->next)
	{
		del((*lst)->content);
		buf = *lst;
		*lst = buf->next;
		free(buf);
	}
	del((*lst)->content);
	free(*lst);
	*lst = 0;
}
