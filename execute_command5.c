/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:59:31 by seyang            #+#    #+#             */
/*   Updated: 2023/02/23 15:47:09 by segan            ###   ########.fr       */
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
	int	size;

	size = 0;
	while (cmd[size])
		size++;
	child->fd = new_pipe(cmd);
	child->launch_cnt = 0;
	child->cmd = cmd;
	child->node_inf = node_inf;
	child->path = NULL;
	child->pid = ft_calloc(sizeof(pid_t), (size + 1));
	return (size);
}
