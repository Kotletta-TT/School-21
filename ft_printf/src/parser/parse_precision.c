#include "../../includes/ft_printf.h"

void	parse_precision(t_ft *ft)
{
	int	num;

	if (ft->str[ft->i] == '-')
	{
		parse_width(ft);
		ft->precision = 0;
	}
	if (!(ft_isdigit(ft->str[ft->i])))
		return ;
	num = 0;
	while (ft_strchr(NUMS, ft->str[ft->i]))
	{
		num = num * 10 + (ft->str[ft->i] - '0');
		ft->i++;
	}
	ft->precision = num;
}
