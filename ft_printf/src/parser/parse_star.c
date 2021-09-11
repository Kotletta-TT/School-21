#include "../../includes/ft_printf.h"

void	parse_star(t_ft *ft)
{
	if (ft->str[ft->i - 1] == '.')
	{
		ft->precision = va_arg(ft->args, int);
		if (ft->precision < 0)
		{
			ft->dot = 0;
			ft->precision = 0;
		}
	}
	else
		ft->width = va_arg(ft->args, int);
	if (ft->width < 0)
	{
		ft->minus = 1;
		ft->width *= -1;
	}
	ft->i++;
}
