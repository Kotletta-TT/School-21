#include "libft.h"
#include "../include/push_swap.h"

long long	ft_atoi(const char *str)
{
	int			sign;
	long long	res;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign = -sign;
		str++;
	}
	res = 0;
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
