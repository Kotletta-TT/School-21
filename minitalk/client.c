#include "minitalk.h"
#include "libft.h"

void	ft_error(int i)
{
	if (i == 1)
		write(2, "Invalid numbers of arguments!\n", 30);
	else if (i == 2)
		write(2, "PID-number not valid!\n", 22);
	else if (i == 3)
		write(2, "Malloc Error!\n", 14);
	else if (i == 4)
		write(2, "Failed signing!\n", 14);
	exit(i);
}

int	*convert_to_byte(char c)
{
	int	i;
	int	*bites;

	bites = ft_calloc(sizeof(int), 8);
	if (!bites)
		ft_error(3);
	i = 0;
	while ((int)c >= 2)
	{
		bites[i++] = c % 2;
		c /= 2;
	}
	bites[i] = c;
	return (bites);
}

void	send_zero(int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_error(4);
		usleep(120);
	}
}

void	send_str(char *str, int pid)
{
	int	i;
	int	*sended;
	int	k;

	k = 0;
	while (str[k])
	{
		sended = convert_to_byte(str[k]);
		i = 0;
		while (i < 8)
		{
			if (sended[i] == 1)
				if (kill(pid, SIGUSR1) == -1)
					ft_error(4);
			if (sended[i] == 0)
				if (kill(pid, SIGUSR2) == -1)
					ft_error(4);
			i++;
			usleep(110);
		}
		k++;
		free(sended);
	}
	send_zero(pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	get_commit;
	int					pid;

	get_commit.sa_flags = SA_SIGINFO;
	get_commit.sa_sigaction = handler_commit;
	if (sigaction(SIGUSR2, &get_commit, 0) == -1)
		ft_error(4);
	if (argc != 3)
		ft_error(1);
	pid = ft_atoi(argv[1]);
	if (!pid)
		ft_error(2);
	send_str(argv[2], pid);
	while (1)
		pause();
}
