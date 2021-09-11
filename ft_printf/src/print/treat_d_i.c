#include "../../includes/ft_printf.h"

void	len_int(t_ft *ft, int arg)
{
	long	n_arg;

	ft->new_arg = arg;
	n_arg = arg;
	if (n_arg == 0)
		ft->li++;
	if (n_arg < 0)
	{
		ft->sign++;
		n_arg *= -1;
		ft->new_arg = n_arg;
	}
	while (n_arg > 0)
	{
		n_arg /= 10;
		ft->li++;
	}
}

void	i_treat_dot(t_ft *ft, int arg)
{
	len_int(ft, arg);
	if (ft->dot)
	{
		if (!ft->precision && !arg && ft->dot)
			ft->my_flag = 2;
		if (ft->precision > (ft->li - ft->sign))
			ft->zer_p = ft->precision - ft->li;
	}
}

void	i_treat_width_zero(t_ft *ft)
{
	if (ft->sign && ft->my_flag != 2)
	{
		while (ft->width-- > (ft->sign + ft->zer_p + ft->li) && ft->dot)
			putchar_result(' ', ft);
		if (!ft->dot)
		{
			putchar_result('-', ft);
			ft->sign--;
		}
		while (ft->width-- > (ft->sign + ft->li) && !ft->dot)
			putchar_result('0', ft);
	}
	else if (!ft->sign && ft->my_flag != 2)
	{
		while (ft->width-- > (ft->zer_p + ft->li) && ft->dot)
			putchar_result(' ', ft);
		ft->width++;
		while (ft->width-- > ft->li && !ft->dot)
			putchar_result('0', ft);
	}
}

void	i_treat_width(t_ft *ft)
{
	if (ft->sign && ft->my_flag != 2)
		while (ft->width-- > (ft->sign + ft->zer_p + ft->li))
			putchar_result(' ', ft);
	else if (!ft->sign && ft->my_flag != 2)
		while (ft->width-- > (ft->zer_p + ft->li))
			putchar_result(' ', ft);
}

void	putchar_result(char c, t_ft *ft)
{
	ft_putchar_fd(c, 1);
	ft->res++;
}
