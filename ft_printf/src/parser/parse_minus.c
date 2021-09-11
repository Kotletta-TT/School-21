#include "../../includes/ft_printf.h"

void	parse_minus(t_ft *ft)
{
	ft->minus = 1;
	ft->i++;
	parse_width(ft);
}
