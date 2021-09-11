#include "../../includes/ft_printf.h"

static void	print_num_func(t_ft *ft)
{
	int	zer_p;
	int	len_x;

	len_x = ft->li;
	zer_p = ft->zer_p;
	if (ft->my_flag == 2)
		return ;
	while (zer_p)
	{
		putchar_result('0', ft);
		zer_p--;
	}
	while (--len_x >= 0)
		putchar_result(ft->hex[len_x], ft);
}

static void	x_treat_minus(t_ft *ft)
{
	if (ft->my_flag != 2)
		while (ft->width-- > (ft->zer_p +ft->li))
			putchar_result(' ', ft);
}

void	p_x_X(t_ft *ft)
{
	x_treat_dot(ft, va_arg(ft->args, unsigned int));
	while (ft->width-- && ft->my_flag == 2)
		putchar_result(' ', ft);
	if (++ft->width)
	{
		if (!ft->minus)
		{
			if (ft->zero)
				x_treat_width_zero(ft);
			if (!ft->zero)
				x_treat_width(ft);
			print_num_func(ft);
		}
		if (ft->minus)
		{
			print_num_func(ft);
			x_treat_minus(ft);
		}
		ft->width++;
	}
	if (!ft->width)
		print_num_func(ft);
	ft->i++;
}
