#include "philo.h"

uint64_t	get_time_now(void)
{
	static struct timeval	time;
	uint64_t				res;

	gettimeofday(&time, NULL);
	res = (time.tv_usec / 1000) + (time.tv_sec * 1000);
	return (res);
}

int	ft_strlen(const char *str)
{
	int	res;

	if (!str)
		return (0);
	res = 0;
	while (str[res])
		res++;
	return (res);
}

int	ft_clear(t_main *mon)
{
	int	j;

	pthread_mutex_destroy(&mon->dead_m);
	pthread_mutex_destroy(&mon->w_m);
	if (mon->philo)
	{
		j = 0;
		while (j < mon->cnt_philo)
			pthread_mutex_destroy(&mon->philo[j++].m);
		free(mon->philo);
	}
	if (mon->f_m)
	{
		j = 0;
		while (j < mon->cnt_philo)
			pthread_mutex_destroy(&mon->f_m[j++]);
		free(mon->f_m);
	}
	return (1);
}

int	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}
