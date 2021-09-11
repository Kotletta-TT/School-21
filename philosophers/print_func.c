#include "philo.h"

void	print_(t_ph *ph, char *str)
{
	uint64_t	time;

	time = get_time_now();
	pthread_mutex_lock(&ph->main->w_m);
	if (!ph->main->die)
		printf("%llu %d %s\n", time - ph->main->begin, ph->id + 1, str);
	pthread_mutex_unlock(&ph->main->w_m);
}

void	check_die(t_ph *ph)
{
	ph->main->die = 1;
	pthread_mutex_unlock(&ph->m);
	pthread_mutex_unlock(&ph->main->dead_m);
}
