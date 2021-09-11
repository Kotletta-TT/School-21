#include "../../includes/ft_printf.h"

void	len_x(t_ft *ft, unsigned int arg)
{
	unsigned int	pre_hex;

	if (!arg)
	{
		ft->hex[0] = '0';
		ft->li++;
	}
	while (arg)
	{
		pre_hex = arg % 16;
		if (pre_hex < 10)
			ft->hex[ft->li++] = 48 + pre_hex;
		else
			if (ft->sign)
				ft->hex[ft->li++] = 55 + pre_hex + 32;
		else
			ft->hex[ft->li++] = 55 + pre_hex;
		arg /= 16;
	}
	ft->hex[ft->li] = 0;
}

void	x_treat_dot(t_ft *ft, unsigned int arg)
{
	len_x(ft, arg);
	if (ft->dot)
	{
		if (!ft->precision && !arg && ft->dot)
			ft->my_flag = 2;
		if (ft->precision > ft->li)
			ft->zer_p = ft->precision - ft->li;
	}
}

void	x_treat_width_zero(t_ft *ft)
{
	while (ft->width-- > (ft->zer_p + ft->li) && ft->dot)
		putchar_result(' ', ft);
	ft->width++;
	while (ft->width-- > (ft->li) && !ft->dot)
		putchar_result('0', ft);
}

void	x_treat_width(t_ft *ft)
{
	if (ft->my_flag != 2)
		while (ft->width-- > (ft->zer_p + ft->li))
			putchar_result(' ', ft);
}
