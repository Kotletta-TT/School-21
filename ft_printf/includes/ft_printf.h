#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_ft
{
	char	zero;
	char	minus;
	int		width;
	int		dot;
	int		precision;
	int		zer_p;
	int		li;
	char	specifier;
	va_list	args;
	char	*str;
	size_t	i;
	int		my_flag;
	int		sign;
	long	new_arg;
	int		res;
	char	*n_arg;
	char	hex[15];
}	t_ft;

typedef struct s_main
{
	size_t	i;
	int		res;
}	t_main;

typedef struct s_arr_func
{
	char	name;
	void	(*f)(t_ft *);
}	t_arr_func;

# define FLAGS "-0.*"
# define NUMS "0123456789"
# define NULL_STR "(null)"
int		ft_printf(const char *fmt, ...);
size_t	parse_ft(t_ft *ft);
void	parse_minus(t_ft *ft);
void	parse_point(t_ft *ft);
void	parse_precision(t_ft *ft);
void	parse_star(t_ft *ft);
void	parse_width(t_ft *ft);
void	parse_zero(t_ft *ft);
void	print_ft(t_ft *ft);
void	p_s(t_ft *ft);
void	p_c(t_ft *ft);
void	p_cc(t_ft *ft);
void	p_d_i(t_ft *ft);
void	p_p(t_ft *ft);
void	p_u(t_ft *ft);
void	p_x_X(t_ft *ft);
void	fill_width(char s, int len);
void	len_int(t_ft *ft, int arg);
void	len_x(t_ft *ft, unsigned int arg);
void	en_u(t_ft *ft, unsigned int arg);
void	len_p(t_ft *ft, unsigned long int arg);
void	putchar_result(char c, t_ft *ft);
void	i_treat_dot(t_ft *ft, int arg);
void	i_treat_width_zero(t_ft *ft);
void	i_treat_width(t_ft *ft);
void	x_treat_dot(t_ft *ft, unsigned int arg);
void	x_treat_width_zero(t_ft *ft);
void	x_treat_width(t_ft *ft);
void	u_treat_dot(t_ft *ft, unsigned int arg);
void	u_treat_width_zero(t_ft *ft);
void	u_treat_width(t_ft *ft);
void	p_treat_dot(t_ft *ft, void *arg);
void	p_treat_width_zero(t_ft *ft);
void	p_treat_width(t_ft *ft);
void	print_0x(t_ft *ft);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(long n, int fd, t_ft *ft);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
#endif
