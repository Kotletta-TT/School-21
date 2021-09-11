#include "minitalk.h"
#include "libft.h"

int	g_bitchar[8];
int	g_index;

char	convert_char(void)
{
	char	c;
	int		c_tmp;
	int		tmp;

	c = 0;
	while (g_index-- >= 0)
	{
		c_tmp = 0;
		if (g_bitchar[g_index] && g_index > 0)
		{
			tmp = g_index;
			c_tmp = 1;
			while (tmp--)
				c_tmp *= 2;
		}
		else if (g_index == 0 && g_bitchar[g_index])
			c_tmp = 1;
		c += c_tmp;
	}
	return (c);
}

void	bit_processing(int bit)
{
	g_bitchar[g_index] = bit;
	g_index += 1;
}

int	print_char(void)
{
	char	c;

	c = convert_char();
	g_index = 0;
	if (c == 0)
		return (1);
	write(1, &c, 1);
	return (0);
}

void	handler_signal(int sigid, siginfo_t *inf, void *unus)
{
	(void)unus;
	if (sigid == SIGUSR1)
	{
		bit_processing(1);
		if (g_index == 8 && print_char())
		{
			if (kill(inf->si_pid, SIGUSR2))
				write(2, "Failed sign!\n", 13);
			ft_bzero(g_bitchar, sizeof(int) * 8);
		}
	}
	else if (sigid == SIGUSR2)
	{
		bit_processing(0);
		if (g_index == 8 && print_char())
		{
			if (kill(inf->si_pid, SIGUSR2))
				write(2, "Failed sign!\n", 13);
			ft_bzero(g_bitchar, sizeof(int) * 8);
		}
	}
}

int	main(void)
{
	struct sigaction	sig_struct;

	g_index = 0;
	sig_struct.sa_flags = SA_SIGINFO;
	sig_struct.sa_sigaction = handler_signal;
	if (sigaction(SIGUSR1, &sig_struct, 0) == -1)
		ft_serror(2);
	if (sigaction(SIGUSR2, &sig_struct, 0) == -1)
		ft_serror(2);
	write(1, "My PID: ", 8);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
}
