#include "pipex.h"

char 		*get_right_path(char *cmd, char **paths)
{
	int		i;
	char	*full_path;

	i = -1;
	while (paths[++i])
	{
		full_path = concat_path(paths[i], cmd);
		if (!access(full_path, X_OK))
			return (full_path);
		free(full_path);
	}
	return (NULL);
}

t_command	**parse_args(t_pipex *json)
{
	t_command	**commands;
	char 		**arr_av;
	int			i;
	int 		k;

	i = 1;
	k = -1;
	commands = malloc(sizeof(t_command *) * (arrlen(json->cpyav) - 1));
	if (!commands)
		return (NULL);
	while (json->cpyav[++i] && i > 0 && (i < arrlen(json->cpyav) - 1))
	{
		commands[++k] = malloc(sizeof(t_command) * 1);
		if (!commands[k])
			return (NULL);
		arr_av = ft_split(json->cpyav[i], ' ');
		commands[k]->full_path = get_right_path(arr_av[0], json->env_paths);
		if (!commands[k]->full_path)
			return (NULL);
		commands[k]->av = arr_av;
		commands[k]->env = json->cpyenv;
	}
	commands[++k] = NULL;
	return (commands);
}