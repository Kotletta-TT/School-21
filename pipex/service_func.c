#include "pipex.h"

void	clear_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int 	ft_errors(char *message)
{
	perror("pipex");
	//	write(2, message, ft_strlen(message));
	return (1);
}

int 	ft_clear(t_pipex json)
{
	if (json.cpyenv)
		clear_arr(json.cpyenv);
	if (json.cpyav)
		clear_arr(json.cpyav);
	if (json.env_paths)
		clear_arr(json.env_paths);
	return (1);
}