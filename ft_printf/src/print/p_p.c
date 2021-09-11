#include "../../includes/ft_printf.h"

void	print_0x(t_ft *ft)
{
	putchar_result('0', ft);
	putchar_result('x', ft);
}

static void	special_case(t_ft *ft)
{
	if (ft->my_flag == 2)
	{
		ft->width -= 2;
		while (ft->width-- > 0 && ft->my_flag == 2)
			putchar_result(' ', ft);
		print_0x(ft);
	}
}

static void	print_num_func(t_ft *ft)
{
	int	zer_p;
	int	len_x;

	len_x = ft->li;
	zer_p = ft->zer_p;
	if (ft->my_flag == 2)
		return ;
	if (zer_p)
	{
		putchar_result(ft->hex[--len_x], ft);
		putchar_result(ft->hex[--len_x], ft);
	}
	while (zer_p)
	{
		putchar_result('0', ft);
		zer_p--;
	}
	while (--len_x >= 0)
		putchar_result(ft->hex[len_x], ft);
}

static void	p_treat_minus(t_ft *ft)
{
	if (ft->my_flag != 2)
		while (ft->width-- > (ft->zer_p +ft->li))
			putchar_result(' ', ft);
}

void	p_p(t_ft *ft)
{
	void	*arg;

	arg = va_arg(ft->args, void *);
	p_treat_dot(ft, arg);
	special_case(ft);
	if (ft->width)
	{
		if (!ft->minus)
		{
			if (ft->zero)
				p_treat_width_zero(ft);
			if (!ft->zero)
				p_treat_width(ft);
			print_num_func(ft);
		}
		if (ft->minus)
		{
			print_num_func(ft);
			p_treat_minus(ft);
		}
		ft->width++;
	}
	if (!ft->width)
		print_num_func(ft);
	ft->i++;
}
