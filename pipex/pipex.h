#ifndef PIPEX_H
#define PIPEX_H
#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
typedef struct	s_command
{
	char				*full_path;
	char 				*file_path;
	char				**av;
	char				**env;
	struct s_command	*next;
}				t_command;
typedef struct	s_pipex
{
	char		**cpyenv;
	char		**env_paths;
	char		**cpyav;
	char		*full_path;
	t_command	**commands;
}				t_pipex;
typedef struct	s_split
{
	char	**arr;
	char 	*temp;
	int 	cnt;
	int 	i;
	int 	start;
	int 	end;
}				t_split;
char		**ft_split(char *str, char separator);
char		**arrcpy(char **src);
t_command	**parse_args(t_pipex *json);
int			ft_strcmpr(const char *s1, const char *s2, int length);
char 		*ft_strcpy(const char *src);
int			arrlen(char **arr);
int			ft_strlen(const char *str);
char 		*concat_path(char *start, char *end);
char		*find_path_in_env(char **env);
char 		**split_paths(char *str);
char		**parse_path(char **env);
char 		*concat_path(char *start, char *end);
int			ft_errors(char *message);
int			ft_clear(t_pipex json);
#define PATH "PATH"
#endif
