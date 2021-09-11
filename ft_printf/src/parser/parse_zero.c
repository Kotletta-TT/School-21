#include "../../includes/ft_printf.h"

void	parse_zero(t_ft *ft)
{
	ft->zero = 1;
	ft->i++;
	parse_width(ft);
}
