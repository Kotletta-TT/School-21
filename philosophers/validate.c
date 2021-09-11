#include "philo.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;

	if (!str)
		return (0);
	res = 0;
	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
		res = res * 10 + (str[i++] - '0');
	return (res);
}

void	validate_philo(t_main *mon)
{
	int	k;

	k = -1;
	while (++k < mon->cnt_philo)
	{
		mon->philo[k].id = k;
		mon->philo[k].l_fork = k;
		mon->philo[k].r_fork = (k + 1) % mon->cnt_philo;
		mon->philo[k].main = mon;
		pthread_mutex_init(&mon->philo[k].m, NULL);
	}
}

void	validate(char **av, t_main *mon)
{
	int	k;

	mon->cnt_philo = ft_atoi(av[1]);
	mon->die_t = ft_atoi(av[2]);
	mon->eat_t = ft_atoi(av[3]);
	mon->sleep_t = ft_atoi(av[4]);
	mon->cnt_eat = ft_atoi(av[5]);
	mon->philo = malloc(sizeof(t_ph) * mon->cnt_philo);
	mon->f_m = malloc(sizeof(pthread_mutex_t) * mon->cnt_philo);
	if (mon->cnt_philo < 2 || mon->cnt_philo > 200 || mon->sleep_t < 60
		|| mon->eat_t < 60 || mon->die_t < 60 || (!mon->philo) || (!mon->f_m))
	{
		ft_clear(mon);
		ft_error("0 1 died\n");
		return ;
	}
	pthread_mutex_init(&mon->dead_m, NULL);
	pthread_mutex_init(&mon->w_m, NULL);
	pthread_mutex_lock(&mon->dead_m);
	k = 0;
	while (k < mon->cnt_philo)
		pthread_mutex_init(&mon->f_m[k++], NULL);
	validate_philo(mon);
}
