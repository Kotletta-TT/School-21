#include "../../includes/ft_printf.h"

static void	print_num_func(t_ft *ft)
{
	int	zer_p;

	zer_p = ft->zer_p;
	if (ft->my_flag == 2)
		return ;
	while (zer_p)
	{
		putchar_result('0', ft);
		zer_p--;
	}
	ft_putnbr_fd(ft->new_arg, 1, ft);
}

static void	u_treat_minus(t_ft *ft)
{
	if (ft->sign <= 0 && ft->my_flag != 2)
		while (ft->width-- > (ft->zer_p +ft->li))
			putchar_result(' ', ft);
}

void	p_u(t_ft *ft)
{
	u_treat_dot(ft, va_arg(ft->args, unsigned int));
	while (ft->width-- && ft->my_flag == 2)
		putchar_result(' ', ft);
	if (++ft->width)
	{
		if (!ft->minus)
		{
			if (ft->zero)
				u_treat_width_zero(ft);
			if (!ft->zero)
				u_treat_width(ft);
			print_num_func(ft);
		}
		if (ft->minus)
		{
			print_num_func(ft);
			u_treat_minus(ft);
		}
		ft->width++;
	}
	if (!ft->width)
		print_num_func(ft);
	ft->i++;
}
