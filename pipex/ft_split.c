#include "pipex.h"

static int	count_str(char *str, char separator)
{
	int	i;

	i = 1;
	while (*str)
		if (*str++ == separator)
			i++;
		return (i);
}

static char	*str_copy_borders(char *str, int start, int end)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
		res[i++] = str[start++];
	res[i] = 0;
	return (res);
}

static int	find_next(const char *str, char separator)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == separator)
			return (i);
		return (i);
}

char		**ft_split(char *str, char separator)
{
	static t_split	data;

	if (!str || !separator)
		return (NULL);
	data.temp = str;
	while (*data.temp == separator)
		data.temp++;
	if (!*data.temp)
		return (NULL);
	data.cnt = count_str(data.temp, separator);
	data.arr = malloc(sizeof(char *) * (data.cnt + 1));
	if (!data.arr)
		return (NULL);
	data.i = 0;
	data.start = 0;
	while (data.i < data.cnt)
	{
		data.end = data.start + find_next(&data.temp[data.start], separator);
		data.arr[data.i++] = str_copy_borders(str, data.start, data.end);
		data.start = data.end + 1;
	}
	data.arr[data.cnt] = 0;
	return (data.arr);
}