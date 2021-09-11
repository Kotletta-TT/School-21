#include "minitalk.h"

void	handler_commit(int ix, siginfo_t *inf, void *g)
{
	(void)ix;
	(void)inf;
	(void)g;
	write(1, "Full message sended!\n", 21);
	exit(0);
}

void	ft_serror(int i)
{
	if (i == 1)
		write(2, "Malloc Error!\n", 30);
	else if (i == 2)
		write(2, "Error signals!\n", 30);
	exit(i);
}
