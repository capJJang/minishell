/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:29:50 by seyang            #+#    #+#             */
/*   Updated: 2022/12/28 19:49:40 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	set_pipe_fd(char ***command, int launch_cnt, int *pipe[2])
// {

// }

void	is_child(char *path, char ***command, int launch_count, int **pipe)
{
	int	check_error;

	check_error = 0;
	if (launch_count == 0)
	{
		if (command[launch_count + 1] != 0)
		{
			check_error += dup2(pipe[launch_count][P_WRITE], STDOUT_FILENO);
			close(pipe[launch_count][P_WRITE]);
		}
	}
	else if (command[launch_count + 1] == 0)
	{
		check_error += dup2(pipe[launch_count - 1][P_READ], STDIN_FILENO);
		close(pipe[launch_count - 1][P_READ]);
	}
	else
	{
		check_error += dup2(pipe[launch_count - 1][P_READ], STDIN_FILENO);
		close(pipe[launch_count - 1][P_READ]);
		check_error += dup2(pipe[launch_count][P_WRITE], STDOUT_FILENO);
		close(pipe[launch_count][P_WRITE]);
	}
	if (check_error < 0 || execve(path, command[launch_count], NULL) == -1)
		exit (-1);
}

void	is_parent(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) == -1)
		perror(strerror(errno));
}

int	**new_pipe(char ***command)
{
	int	n;
	int	**fd;

	n = 0;
	while (command[n])
		n++;
	fd = ft_malloc(sizeof(int *) * (n + 1));
	fd[n] = 0;
	while (n > 0)
		fd[--n] = ft_malloc(sizeof(int) * 2);
	while (fd[n])
		if (pipe(fd[n++]) == -1)
			exit (-1);
	return (fd);
}

void	close_pipe(int **fd)
{
	int	i;

	i = 0;
	while (fd[i])
	{
		close(fd[i][P_READ]);
		close(fd[i][P_WRITE]);
		i++;
	}
}

void	execute_command(char **path_env, char ***command, t_node_inf *node_inf)
{
	pid_t	pid;
	int		**fd;
	int		launch_cnt;
	char	*path;

	fd = new_pipe(command);
	launch_cnt = 0;
	while (command[launch_cnt])
	{
		path = get_path(path_env, command[launch_cnt][0]);
		if (path == IS_NOT_FOUND)
		{
			print_cmd_nfound(IS_NOT_FOUND, command[launch_cnt][0]);
			break ;
		}
		(void) node_inf;
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
