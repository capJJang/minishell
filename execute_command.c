/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:29:50 by seyang            #+#    #+#             */
/*   Updated: 2023/02/24 18:42:11 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_child(t_child child, char **path_env, int size)
{
	t_node		*curr;
	int			path_stat;

	child.path = get_path(path_env, child.cmd[child.launch_cnt][0], &path_stat);
	if (path_stat > 0 && !is_builtin(child.cmd[child.launch_cnt]))
	{
		print_cmd_nfound(path_stat, child.cmd[child.launch_cnt][0]);
		exit(127);
	}
	curr = is_redirection(child);
	if (child.launch_cnt == 0)
		set_first_pipe(&child, curr, size);
	else if (child.cmd[child.launch_cnt + 1] == 0)
		set_end_pipe(&child, curr, size);
	else
		set_middle_pipe(&child, curr, size);
	if (is_builtin(child.cmd[child.launch_cnt]))
		exe_builtin(child.node_inf);
	else if (execve(child.path, \
		child.cmd[child.launch_cnt], child.node_inf->vars->env) == -1)
		print_errno_in_child(0);
}

int	wait_child(pid_t *pid, int *status, int size, int **fd)
{
	int	temp;
	int	i;

	i = 0;
	temp = size;
	close_pipe(fd);
	while (0 < temp)
	{
		if (waitpid(pid[temp - 1], &status[temp - 1], 0) != -1)
		{
			temp = size;
			i = -1;
		}
		temp--;
		i++;
	}
	return (i);
}

void	is_parent(t_node_inf *node_inf, pid_t *pid, int size, int **fd)
{
	int	*status;
	int	i;

	set_parent_signal();
	status = (int *)ft_calloc(size, sizeof(int));
	i = wait_child(pid, status, size, fd);
	i += (i == 0);
	*node_inf->vars->stat = status[size - 1] % 255;
	if (i != 0 && WIFSIGNALED(status[i - 1]) && status[i - 1] != SIGPIPE)
	{
		if (status[i - 1] == 3)
			printf("Quit : %d", status[i - 1]);
		printf("\n");
		*node_inf->vars->stat = (status[size - 1] + 128) % 255;
	}
	free(status);
}

void	fork_child(t_child *child, int size, t_node_inf *node_inf, char ***cmd)
{
	while (child->launch_cnt < size)
	{
		child->pid[child->launch_cnt] = ft_fork();
		if (child->pid[child->launch_cnt] == 0)
			break ;
		if (child->pid[child->launch_cnt] == -1)
			exit (-1);
		node_inf->cmd = cmd[child->launch_cnt];
		child->launch_cnt++;
	}
}

void	execute_command(char **path_env, char ***cmd, t_node_inf *node_inf)
{
	t_child	child;
	int		size;
	int		std_fd[2];

	size = init_cmd_var(&child, cmd, node_inf);
	std_fd[0] = dup(STDIN_FILENO);
	std_fd[1] = dup(STDOUT_FILENO);
	update__(child);
	if ((is_redirection2(node_inf) && ft_node_strncmp(node_inf, "|")) \
		|| is_redirection3(node_inf))
		redirect_pipe(&child, is_all_redirection(child), true);
	node_inf->cmd = cmd[child.launch_cnt];
	if ((is_builtin(cmd[child.launch_cnt]) && ft_node_strncmp(node_inf, "|")))
		exe_builtin(node_inf);
	else
	{
		fork_child(&child, size, node_inf, cmd);
		if (child.pid[child.launch_cnt] == 0 && child.launch_cnt != size)
			is_child(child, path_env, size);
		else
			is_parent(node_inf, child.pid, size, child.fd);
	}
	rollback_std_fd(node_inf, std_fd);
	ft_free_runtime(child.pid, child.fd, path_env);
	unlink("*&$@^857sdf{}.:<<12#@");
}
