#include "push_swap.h"

void	init_cont(t_content *content, long long arr)
{
	content->num = (int)arr;
	content->flag = 0;
	content->index = 0;
}

void	ft_lstadd_bck(t_lst **lst, t_lst *new)
{
	t_lst	*cpy_lst;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	cpy_lst = *lst;
	while (cpy_lst->next)
		cpy_lst = cpy_lst->next;
	cpy_lst->next = new;
}

t_lst	*ft_lst_new(int arr)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst) * 1);
	if (!new)
		return (NULL);
	init_cont(&new->content, arr);
	new->next = NULL;
	return (new);
}

t_lst	*init_lst(int *arr, int argc)
{
	int		i;
	t_lst	*tmp;
	t_lst	*res;

	i = 0;
	res = 0;
	while (i < argc)
	{
		tmp = ft_lst_new(arr[i]);
		if (!tmp)
			ft_error(0, 0, &res);
		ft_lstadd_bck(&res, tmp);
		i++;
	}
	return (res);
}

t_lst	*lst_last(t_lst *lst)
{
	t_lst	*last;

	while (lst->next)
		lst = lst->next;
	last = lst;
	return (last);
}
