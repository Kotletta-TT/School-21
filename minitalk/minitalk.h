#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
void	handler_commit(int ix, siginfo_t *inf, void *g);
void	ft_serror(int i);
#endif
