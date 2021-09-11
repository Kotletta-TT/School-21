#include "../../includes/ft_printf.h"

void	fill_width(char c, int len)
{
	while (len-- > 0)
		write(1, &c, 1);
}

static void	init_arr_func(t_arr_func *arr_func)
{
	arr_func[0].name = 'c';
	arr_func[0].f = p_c;
	arr_func[1].name = 's';
	arr_func[1].f = p_s;
	arr_func[2].name = 'd';
	arr_func[2].f = p_d_i;
	arr_func[3].name = 'i';
	arr_func[3].f = p_d_i;
	arr_func[4].name = 'p';
	arr_func[4].f = p_p;
	arr_func[5].name = 'u';
	arr_func[5].f = p_u;
	arr_func[6].name = 'x';
	arr_func[6].f = p_x_X;
	arr_func[7].name = 'X';
	arr_func[7].f = p_x_X;
	arr_func[8].name = '}';
	arr_func[8].f = p_cc;
	arr_func[9].name = 0;
	arr_func[9].f = 0;
}

void	print_ft(t_ft *ft)
{
	int			i;
	t_arr_func	arr_func[10];

	i = 0;
	init_arr_func(arr_func);
	if (!ft->specifier)
		return ;
	while (arr_func[i].name != ft->specifier && arr_func[i].name)
		i++;
	if (arr_func[i].name != ft->specifier)
		arr_func[8].f(ft);
	else
		arr_func[i].f(ft);
}
