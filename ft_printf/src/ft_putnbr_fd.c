#include "../includes/ft_printf.h"

static void	r_ft_putnmbr(long n, int fd, t_ft *ft)
{
	char	c;

	if (n == 0)
		return ;
	r_ft_putnmbr(n / 10, fd, ft);
	c = n % 10;
	c += '0';
	putchar_result(c, ft);
}

void	ft_putnbr_fd(long n, int fd, t_ft *ft)
{
	if (n == 0)
		putchar_result('0', ft);
	r_ft_putnmbr(n, fd, ft);
}
