#include "../../includes/ft_printf.h"

static size_t	parse_flag(t_ft *ft)
{
	if (ft->str[ft->i] == '0')
		parse_zero(ft);
	if (ft->str[ft->i] == '-')
		parse_minus(ft);
	if (ft->str[ft->i] == '*')
		parse_star(ft);
	if (ft->str[ft->i] == '.')
		parse_point(ft);
	return (0);
}

size_t	parse_ft(t_ft *ft)
{
	while (ft->str[ft->i])
	{
		if (ft_strchr(FLAGS, ft->str[ft->i]))
		{
			parse_flag(ft);
			continue ;
		}
		else if (ft_strchr(NUMS, ft->str[ft->i]))
		{
			parse_width(ft);
			continue ;
		}
		else
		{
			ft->specifier = ft->str[ft->i];
			if (ft->specifier == 'x')
				ft->sign = 1;
			break ;
		}
	}
	return (ft->i);
}
