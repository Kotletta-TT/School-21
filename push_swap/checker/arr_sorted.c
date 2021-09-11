#include "checker.h"

void	init_index(t_lst *lst, int *arr, int argc)
{
	int	i;
	int	tmp;

	while (lst)
	{
		i = -1;
		tmp = argc;
		while (++i <= tmp)
		{
			if (lst->content.num == arr[i])
			{
				lst->content.index = i + 1;
				break ;
			}
		}
		lst = lst->next;
	}
}

void	ft_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int	part(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	k;

	pivot = (arr[low] + arr[high]) / 2;
	i = low;
	k = high;
	while (1)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[k] > pivot)
			k--;
		if (i >= k)
			return (k);
		ft_swap(&arr[i++], &arr[k--]);
	}
}

void	ft_qsort(int *arr, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = part(arr, low, high);
		ft_qsort(arr, low, pivot);
		ft_qsort(arr, pivot + 1, high);
	}
}
