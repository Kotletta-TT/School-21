#include "checker.h"
#include "libft.h"

t_main	*init_info_struct(int argc)
{
	t_main	*res;

	res = malloc(sizeof(t_main) * 1);
	if (!res)
		return (NULL);
	res->next = 1;
	res->flag = 0;
	res->max = argc;
	res->mid = (argc + res->next) / 2;
	res->first = 1;
	res->buf_flag = 0;
	res->log_str = 0;
	return (res);
}

int	len_lst(t_lst *lst)
{
	int	res;

	res = 0;
	while (lst)
	{
		res++;
		lst = lst->next;
	}
	return (res);
}

void	ft_lstcler(t_lst **lst)
{
	t_lst	*buf;

	if (!lst)
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
