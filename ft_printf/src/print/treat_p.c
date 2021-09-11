#include "../../includes/ft_printf.h"

void	len_p(t_ft *ft, unsigned long int arg)
{
	unsigned long int	pre_hex;

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
			ft->hex[ft->li++] = 55 + pre_hex + 32;
		arg /= 16;
	}
	ft->hex[ft->li++] = 'x';
	ft->hex[ft->li++] = '0';
	ft->hex[ft->li] = 0;
}

void	p_treat_dot(t_ft *ft, void *arg)
{
	unsigned long int	narg;

	narg = (unsigned long int)arg;
	len_p(ft, narg);
	if (ft->dot)
	{
		if (!ft->precision && !narg && ft->dot)
			ft->my_flag = 2;
		if (ft->precision > ft->li)
			ft->zer_p = ft->precision - ft->li + 2;
	}
}

void	p_treat_width_zero(t_ft *ft)
{
	while (ft->width-- > (ft->zer_p + ft->li) && ft->dot)
		putchar_result(' ', ft);
	ft->width++;
	while (ft->width-- > (ft->li) && !ft->dot)
		putchar_result('0', ft);
}

void	p_treat_width(t_ft *ft)
{
	if (ft->my_flag != 2)
		while (ft->width-- > (ft->zer_p + ft->li))
			putchar_result(' ', ft);
}
