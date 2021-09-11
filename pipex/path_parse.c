#include "pipex.h"

char	*find_path_in_env(char **env)
{
	int	i;

	if (!env)
		return (NULL);
	i = -1;
	while (env[++i])
		if (ft_strcmpr(env[i], PATH, ft_strlen(PATH)))
			return (env[i]);
		return (NULL);
}

char 	**split_paths(char *str)
{
	char 	*tmp;
	char	**paths;

	tmp = str;
	while (*tmp != '=' && *tmp)
		tmp++;
	if (!*tmp)
		return (NULL);
	paths = ft_split(++tmp, ':');
	return (paths);
}

char	**parse_path(char **env)
{
	char *temp_path_str;

	if (!env)
		return (NULL);
	temp_path_str = find_path_in_env(env);
	if (!temp_path_str)
		return (NULL);
	return (split_paths(temp_path_str));
}

char 	*concat_path(char *start, char *end)
{
	char *res;
	int i;

	res = malloc(sizeof(char) * (ft_strlen(start) + ft_strlen(end) + 2));
	if (!res || !end)
		return (NULL);
	i = 0;
	while (*start)
		res[i++] = *start++;
	res[i++] = '/';
	while (*end)
		res[i++] = *end++;
	res[i] = 0;
	return (res);
}