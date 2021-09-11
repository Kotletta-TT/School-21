#include "../includes/ft_printf.h"

static void	init_main(t_main *ft_main)
{
	ft_main->i = 0;
	ft_main->res = 0;
}

static void	init_ft(t_ft *ft, char *fmt)
{
	ft->minus = 0;
	ft->zero = 0;
	ft->width = 0;
	ft->precision = 0;
	ft->zer_p = 0;
	ft->li = 0;
	ft->my_flag = 0;
	ft->dot = 0;
	ft->specifier = 0;
	ft->str = fmt;
	ft->sign = 0;
	ft->i = 1;
	ft->res = 0;
	ft->new_arg = 0;
	ft->n_arg = NULL_STR;
}

int	ft_printf(const char *fmt, ...)
{
	t_ft		ft;
	t_main		ft_main;

	init_main(&ft_main);
	va_start(ft.args, fmt);
	while (fmt[ft_main.i])
	{
		if (fmt[ft_main.i] == '%')
		{
			init_ft(&ft, (char *)&fmt[ft_main.i]);
			parse_ft(&ft);
			print_ft(&ft);
			ft_main.i += ft.i;
			ft_main.res += ft.res;
		}
		else if (fmt[ft_main.i])
		{
			ft_putchar_fd(fmt[ft_main.i], 1);
			ft_main.i++;
			ft_main.res++;
		}
	}
	va_end(ft.args);
	return (ft_main.res);
}
