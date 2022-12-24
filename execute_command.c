/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:29:50 by seyang            #+#    #+#             */
/*   Updated: 2022/12/25 04:19:26 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	set_pipe_fd(char ***command, int launch_count, int *pipe[2])
// {

// }

void	is_child(char *path, char ***command, int launch_count, int pipe[2])
{
	// set_pipe_fd(command, launch_count, &pipe);
	int	read_fd;
	int	write_fd;
	//char	buffer[4096];

	if (path == IS_NOT_FOUND)
		printf("bash: %s: command not found\n", command[launch_count][0]);
//		print_cmd_nfound(IS_NOT_FOUND, command[launch_count][0]);
	if (command[launch_count + 1] == 0)
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
	else if (launch_count == 0)
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
	if (execve(path, command[launch_count], NULL) == -1)
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
	int		launch_count;
	char	*path;
	
	(void) node_inf;
	if (pipe(fd) == -1)
		exit (-1);
	launch_count = 0;
	while (command[launch_count])
	{
		if (!ft_strncmp(*command[launch_count], "exit", ft_strlen(*command[launch_count])))
			builtin_exit(node_inf);
		pid = ft_fork();
		if (pid == -1)
			exit (-1);
		path = get_path(path_env, command[launch_count][0]);
		if (pid == 0)
			is_child(path, command, launch_count, fd);
		else
			is_parent(pid);
		launch_count++;
	}
}