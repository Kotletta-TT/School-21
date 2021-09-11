#include "push_swap.h"

void	s_1(t_lst **a, t_main *info)
{
	swap(a, 0, "sa\n", info);
	rotate(a, 0, "ra\n", info);
}

void	s_2(t_lst **a, t_main *info)
{
	swap(a, 0, "sa\n", info);
}

void	s_3(t_lst **a, t_main *info)
{
	rotate(a, 0, "ra\n", info);
}

void	s_4(t_lst **a, t_main *info)
{
	reverse_rotate(a, 0, "rra\n", info);
}

void	s_5(t_lst **a, t_main *info)
{
	rotate(a, 0, "ra\n", info);
	swap(a, 0, "sa\n", info);
}
