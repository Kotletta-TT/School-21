#include "philo.h"

int	main(int ac, char **av)
{
	static t_main	mon;

	if (ac < 5 || ac > 6)
		return (ft_error("Error argument"));
	validate(av, &mon);
	init_threads(&mon);
	pthread_mutex_lock(&mon.dead_m);
	pthread_mutex_unlock(&mon.dead_m);
	return (0);
}
