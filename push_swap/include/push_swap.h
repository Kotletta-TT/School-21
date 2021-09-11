#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef LIBFT_H
#  include "libft.h"
# endif
# include <unistd.h>
# include <stdlib.h>
typedef struct s_content
{
	int	num;
	int	flag;
	int	index;
}	t_content;
typedef struct s_lst
{
	t_content		content;
	struct s_lst	*next;
}	t_lst;
typedef struct s_main
{
	int		next;
	int		mid;
	int		max;
	int		flag;
	int		first;
	int		buf_flag;
	t_list	*log_str;
}	t_main;
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN  -2147483648
# endif
int		ft_error(char **arr, char **arr2, t_lst **lst);
void	ft_flash_arr(char **arr);
int		ft_arrlen(char **arr);
int		is_int(char *str);
int		is_normal_format(char *str);
void	validate_args(char **splt);
t_lst	*validate_input(int argc, char **argv);
void	ft_qsort(int *arr, int low, int high);
t_lst	*init_lst(int *arr, int argc);
void	init_index(t_lst *lst, int *arr, int argc);
void	ft_sorted(t_lst *lst);
t_main	*init_info_struct(int argc);
int		len_lst(t_lst *lst);
t_lst	*lst_last(t_lst *lst);
void	push(t_lst **from, t_lst **to, char *s, t_main *info);
void	rotate(t_lst **lst, t_lst **buf, char *s, t_main *info);
void	reverse_rotate(t_lst **lst, t_lst **buf, char *s, t_main *info);
void	swap(t_lst **lst, t_lst **buf, char *s, t_main *info);
t_lst	*lst_last(t_lst *lst);
void	s_1(t_lst **a, t_main *info);
void	s_2(t_lst **a, t_main *info);
void	s_3(t_lst **a, t_main *info);
void	s_4(t_lst **a, t_main *info);
void	s_5(t_lst **a, t_main *info);
void	start_2(t_lst **a, t_main *info);
void	start_3(t_lst **a, t_main *info);
void	start_4(t_lst **a, t_lst **b, t_main *info);
void	start_5(t_lst **a, t_lst **b, t_main *info);
void	small_algoritm(t_lst **a, t_lst **b, t_main *info);
void	calc_midmax(t_main *info);
void	print_list(t_list *list);
void	n_calc_midmax(t_main *info);
void	speed_start_a(t_lst **a_lst, t_main *info);
void	speed_two(t_lst **a, t_main *info, int *mv);
void	max_index_flag(t_lst *lst, t_main *info);
int		count_move(t_lst *lst, int flag, t_main *info);
int		start_move(int mv, t_lst **a, t_lst **b, t_main *info);
void	speed_tree(t_lst **lst_a, t_lst **lst_b, t_main *info);
void	start_func(t_lst **lst_a, t_lst **lst_b, t_main *info, int flag);
void	mid_func(t_lst **lst_b, t_lst **lst_a, t_main *info, int flag);
void	clean_b(t_lst **a_lst, t_lst **b_lst, t_main *info);
int		check_empty_flag(t_lst *lst, t_main *info);
void	first_order(t_lst **b_lst, t_lst **a_lst, t_main *info);
void	push_flag(t_lst **a_lst, t_lst **b_lst, t_main *info);
void	big_algoritm(t_lst **a_lst, t_lst **b_lst, t_main *info);
void	clear_log(t_list **list);
void	ft_sorted(t_lst *lst);
void	ft_lstcler(t_lst **lst);
int		*convert_si(char **str);
void	check_double(int *arr, int len_arr);
t_lst	*validate_input(int argc, char **argv);
char	**add_to_arr(char **s1, char **s2);
int		check_win(t_lst *a_lst, t_lst *b_lst);
#endif
