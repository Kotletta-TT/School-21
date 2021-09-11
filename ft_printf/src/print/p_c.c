#include "../../includes/ft_printf.h"

static void	print_zero(t_ft *ft, const char arg)
{
	fill_width('0', (ft->width - 1));
	write(1, &arg, 1);
}

static void	print_minus(t_ft *ft, const char arg)
{
	write(1, &arg, 1);
	fill_width(' ', (ft->width - 1));
}

void	p_c(t_ft *ft)
{
	char	arg;

	arg = va_arg(ft->args, int);
	if (ft->zero && !(ft->minus))
		print_zero(ft, arg);
	else if (ft->minus)
		print_minus(ft, arg);
	else
	{
		fill_width(' ', (ft->width - 1));
		write(1, &arg, 1);
	}
	ft->i++;
	if (ft->width < 1)
		ft->res = 1;
	else
		ft->res = ft->width;
}
