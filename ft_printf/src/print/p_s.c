#include "../../includes/ft_printf.h"

static size_t	print_dot(t_ft *ft, const char *arg)
{
	if (ft->dot)
	{
		if ((size_t)ft->precision < ft_strlen(arg))
			return (ft->precision);
	}
	return (ft_strlen(arg));
}

static void	print_str(int len, const char *arg)
{
	while (len--)
		write(1, arg++, 1);
}

static void	print_zero(t_ft *ft, const char *arg)
{
	ft->precision = (int)print_dot(ft, arg);
	fill_width('0', (ft->width - ft->precision));
	print_str(ft->precision, arg);
}

static void	print_minus(t_ft *ft, const char *arg)
{
	ft->precision = (int)print_dot(ft, arg);
	print_str(ft->precision, arg);
	fill_width(' ', (ft->width - ft->precision));
}

void	p_s(t_ft *ft)
{
	char	*arg;

	arg = va_arg(ft->args, char *);
	if (!arg)
		arg = ft->n_arg;
	if (ft->zero && !(ft->minus))
		print_zero(ft, arg);
	else if (ft->minus)
		print_minus(ft, arg);
	else
	{
		ft->precision = (int)print_dot(ft, arg);
		fill_width(' ', (ft->width - ft->precision));
		print_str(ft->precision, arg);
	}
	if (ft->width <= ft->precision)
		ft->res = ft->precision;
	else
		ft->res = ft->width;
	ft->i++;
}
