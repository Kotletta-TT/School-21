#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
struct	s_ph;
typedef struct s_main
{
	int				cnt_philo;
	int				die_t;
	int				eat_t;
	int				sleep_t;
	int				cnt_eat;
	int				die;
	uint64_t		begin;
	struct s_ph		*philo;
	pthread_mutex_t	*f_m;
	pthread_mutex_t	w_m;
	pthread_mutex_t	dead_m;
}				t_main;
typedef struct s_ph
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				cnt_eat_p;
	int				eating;
	uint64_t		eat_lst;
	uint64_t		die_time;
	t_main			*main;
	pthread_mutex_t	m;
}				t_ph;
int			ft_strlen(const char *str);
int			ft_error(char *str);
int			ft_clear(t_main *mon);
uint64_t	get_time_now(void);
void		print_(t_ph *ph, char *str);
void		validate(char **av, t_main *mon);
int			init_threads(t_main *mon);
void		check_die(t_ph *ph);
#endif
