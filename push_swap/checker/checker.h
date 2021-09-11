#ifndef CHECKER_H
# define CHECKER_H
# ifndef LIBFT_H
#  include "libft.h"
# endif
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
void	reverse_rotate(t_lst **lst, t_lst **buf, char *s, t_main *info);
void	rotate(t_lst **lst, t_lst **buf, char *s, t_main *info);
void	push(t_lst **from, t_lst **to, char *s, t_main *info);
void	swap(t_lst **lst, t_lst **buf, char *s, t_main *info);
void	add_log(char *str, t_main *info);
t_main	*init_info_struct(int argc);
int		len_lst(t_lst *lst);
void	ft_lstcler(t_lst **lst);
int		*convert_si(char **str);
void	check_double(int *arr, int len_arr);
t_lst	*validate_input(int argc, char **argv);
int		ft_error(char **arr, char **arr2, t_lst **lst);
int		check_win(t_lst *a_lst, t_lst *b_lst);
void	init_cont(t_content *content, long long arr);
void	ft_lstadd_bck(t_lst **lst, t_lst *new);
t_lst	*ft_lst_new(int arr);
t_lst	*init_lst(int *arr, int argc);
t_lst	*lst_last(t_lst *lst);
char	**add_to_arr(char **s1, char **s2);
int		ft_arrlen(char **arr);
void	validate_args(char **splt);
int		is_normal_format(char *str);
int		is_int(char *str);
void	ft_flash_arr(char **arr);
void	ft_qsort(int *arr, int low, int high);
void	init_index(t_lst *lst, int *arr, int argc);
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN  -2147483648
# endif
#endif
