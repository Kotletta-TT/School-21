#include "pipex.h"

int		main(int ac, char **av, char **env)
{
	(void)ac;
	int				i;
	int				status;
	pid_t			pid;
	static t_pipex	json;

	if (ac < 5)
		return (ft_errors("Error: incorrect number of arguments\n"));
	json.cpyenv = arrcpy(env);
	json.cpyav = arrcpy(av);
	if (!json.cpyenv || !json.cpyav)
		return (ft_clear(json) && ft_errors("Error: Malloc error\n"));
	json.env_paths = parse_path(json.cpyenv);
	if (!json.env_paths)
		return (ft_errors(""));
	json.commands = parse_args(&json);
	pid = fork();
	if (pid)
	{
		waitpid(pid, &status, 0);
		printf("Return to main process\n");
	}
	else
		execve(json.commands[0]->full_path, json.commands[0]->av, json
		.commands[0]->env);


//	execve(json.full_path, test, json.cpyenv);
//
//	ft_clear(json);

//	int fd;
//	int closed;
//	int rm;
//
//	fd = open("../test.c", O_WRONLY);
//	printf("%d\n", fd);
//	closed = close(fd);
//	printf("%d\n", closed);
//	rm = unlink("../test.c");a
//	printf("%d\n", rm)s
	return (0);
}