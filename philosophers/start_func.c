#include "philo.h"

void	life_cycle_func(t_ph *ph)
{
	if (ph->main->die)
		return ;
	pthread_mutex_lock(&ph->main->f_m[ph->l_fork]);
	print_(ph, "has taken a fork");
	pthread_mutex_lock(&ph->main->f_m[ph->r_fork]);
	print_(ph, "has taken a fork");
	pthread_mutex_lock(&ph->m);
	ph->eating = 1;
	ph->eat_lst = get_time_now();
	ph->die_time = ph->eat_lst + ph->main->die_t;
	print_(ph, "is eating");
	usleep(ph->main->eat_t * 1000);
	ph->cnt_eat_p++;
	ph->eating = 0;
	pthread_mutex_unlock(&ph->m);
	print_(ph, "is sleeping");
	pthread_mutex_unlock(&ph->main->f_m[ph->l_fork]);
	pthread_mutex_unlock(&ph->main->f_m[ph->r_fork]);
	usleep(ph->main->sleep_t * 1000);
	print_(ph, "is thinking");
}

int 	check_all_cnt(t_ph *ph)
{
	int	i;

	i = -1;
	while (++i < ph->main->cnt_philo)
	{
		if (ph->main->philo[i].cnt_eat_p < ph->main->cnt_eat)
			return (0);
	}
	return (1);
}

void	*mon_func(void *ph_v)
{
	t_ph		*ph;

	ph = ph_v;
	while (1)
	{
		pthread_mutex_lock(&ph->m);
		if (ph->main->cnt_eat && ph->cnt_eat_p >= ph->main->cnt_eat)
		{
			if (check_all_cnt(ph))
			{
				check_die(ph);
				return (0);
			}
		}
		if (!ph->eating && get_time_now() > ph->die_time)
		{
			print_(ph, "died");
			check_die(ph);
			return (0);
		}
		pthread_mutex_unlock(&ph->m);
		usleep(1000);
	}
}

void	*philo_func(void *ph_v)
{
	pthread_t	id;
	t_ph		*ph;

	ph = ph_v;
	ph->eat_lst = get_time_now();
	ph->die_time = ph->main->die_t + ph->eat_lst;
	if (pthread_create(&id, NULL, &mon_func, ph_v) != 0)
		return ((void *) 1);
	pthread_detach(id);
	usleep(100);
	if (ph->main->cnt_eat)
		while (ph->cnt_eat_p < ph->main->cnt_eat)
			life_cycle_func(ph);
	else
		while (1)
			life_cycle_func(ph);
	return ((void *)0);
}

int	init_threads(t_main *mon)
{
	pthread_t	id;
	int			k;

	mon->begin = get_time_now();
	k = 0;
	while (k < mon->cnt_philo)
	{
		if (pthread_create(&id, NULL, &philo_func, (void *)&mon->philo[k]) != 0)
			return (1);
		pthread_detach(id);
		usleep(100);
		k++;
	}
	return (0);
}
