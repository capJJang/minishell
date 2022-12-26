/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:29:50 by seyang            #+#    #+#             */
/*   Updated: 2022/12/27 01:26:54 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	set_pipe_fd(char ***command, int launch_cnt, int *pipe[2])
// {

// }

void	is_child(char *path, char ***command, int launch_cnt, int pipe[2])
{
	// set_pipe_fd(command, launch_cnt, &pipe);
	int	read_fd;
	int	write_fd;
	//char	buffer[4096];

	if (path == IS_NOT_FOUND)
		printf("bash: %s: command not found\n", command[launch_cnt][0]);
//		print_cmd_nfound(IS_NOT_FOUND, command[launch_cnt][0]);
	if (command[launch_cnt + 1] == 0)
	{
		read_fd = dup2(pipe[P_READ], STDIN_FILENO);
		close(pipe[P_READ]);
		pipe[P_READ] = read_fd;
		//write_fd = dup2(fd, STDOUT_FILENO);
		//close(pipe[P_WRITE]);
		//pipe[P_WRITE] = write_fd;
		// int	ret = read(STDIN_FILENO, buffer, 4096);
		// buffer[ret] = 0;
		// write(STDOUT_FILENO, buffer, ft_strlen(buffer));
	}
	else if (launch_cnt == 0)
	{
		close(pipe[P_READ]);
		write_fd = dup2(pipe[P_WRITE], STDOUT_FILENO);
		close(pipe[P_WRITE]);
		pipe[P_WRITE] = write_fd;
	}
	else
	{
		read_fd = dup2(pipe[P_READ], STDIN_FILENO);
		close(pipe[P_READ]);
		pipe[P_READ] = read_fd;
		write_fd = dup2(pipe[P_WRITE], STDOUT_FILENO);
		close(pipe[P_WRITE]);
		pipe[P_WRITE] = write_fd;
	}
	if (execve(path, command[launch_cnt], NULL) == -1)
		exit (-1);
	exit(0);
}

void	is_parent(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
}

void	execute_command(char **path_env, char ***command, t_node_inf *node_inf)
{
	pid_t	pid;
	int		fd[2];
	int		launch_cnt;
	char	*path;

	if (pipe(fd) == -1)
		exit (-1);
	launch_cnt = 0;
	while (command[launch_cnt])
	{
		if (is_builtin(command[launch_cnt]) && !ft_node_strncmp(node_inf, "|"))
			exe_builtin(node_inf);
		else
		{
			pid = ft_fork();
			if (pid == -1)
				exit (-1);
			path = get_path(path_env, command[launch_cnt][0]);
			if (pid == 0)
				is_child(path, command, launch_cnt, fd);
			else
				is_parent(pid);
		}
		launch_cnt++;
		free(path);
		path = NULL;
	}
}
