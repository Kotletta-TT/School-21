#include "../../includes/ft_printf.h"

void	parse_point(t_ft *ft)
{
	ft->dot = 1;
	ft->i++;
	parse_precision(ft);
}
