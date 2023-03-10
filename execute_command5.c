/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:59:31 by seyang            #+#    #+#             */
/*   Updated: 2023/03/06 21:33:07 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**new_pipe(char ***cmd)
{
	int	n;
	int	**fd;

	n = 0;
	while (cmd[n])
		n++;
	n--;
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

int	init_cmd_var(t_child *child, char ***cmd, t_node_inf *node_inf)
{
	int					size;
	extern sig_atomic_t	g_heredoc_stat;

	size = 0;
	while (cmd[size])
		size++;
	child->fd = new_pipe(cmd);
	child->launch_cnt = 0;
	child->cmd = cmd;
	child->node_inf = node_inf;
	child->path = NULL;
	child->pid = ft_calloc(sizeof(pid_t), (size + 1));
	update__(*child);
	g_heredoc_stat = 1;
	node_inf->cmd = cmd[child->launch_cnt];
	return (size);
}

int	check_is_file(t_node_inf *node_inf)
{
	t_node	*curr;

	curr = node_inf->head;
	while (1)
	{
		if (curr->is_file == 1)
			return (1);
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
	return (0);
}

void	end_execute(t_node_inf *node_inf, int std_fd[2], \
	t_child *child, char ***path_env)
{
	rollback_std_fd(node_inf, std_fd);
	ft_free_runtime(child->pid, child->fd, *path_env);
	unlink("*&$@^857sdf{}.:<<12#@");
}
