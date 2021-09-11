#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_lst	*lst;

	argc--;
	argv++;
	if (!argc)
		exit(0);
	lst = validate_input(argc, argv);
	ft_sorted(lst);
}
