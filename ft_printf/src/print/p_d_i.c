#include "../../includes/ft_printf.h"

static void	print_num_func(t_ft *ft)
{
	int	zer_p;

	zer_p = ft->zer_p;
	if (ft->my_flag == 2)
		return ;
	if (ft->sign)
		putchar_result('-', ft);
	while (zer_p)
	{
		putchar_result('0', ft);
		zer_p--;
	}
	ft_putnbr_fd(ft->new_arg, 1, ft);
}

static void	i_treat_minus(t_ft *ft)
{
	if (ft->sign > 0 && ft->my_flag != 2)
		while (ft->width-- > (ft->sign + ft->zer_p + ft->li))
			putchar_result(' ', ft);
	else if (ft->sign <= 0 && ft->my_flag != 2)
		while (ft->width-- > (ft->zer_p +ft->li))
			putchar_result(' ', ft);
}

void	p_d_i(t_ft *ft)
{
	i_treat_dot(ft, va_arg(ft->args, int));
	while (ft->width-- && ft->my_flag == 2)
		putchar_result(' ', ft);
	if (++ft->width)
	{
		if (!ft->minus)
		{
			if (ft->zero)
				i_treat_width_zero(ft);
			if (!ft->zero)
				i_treat_width(ft);
			print_num_func(ft);
		}
		if (ft->minus)
		{
			print_num_func(ft);
			i_treat_minus(ft);
		}
		ft->width++;
	}
	else
		print_num_func(ft);
	ft->i++;
}
