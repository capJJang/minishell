/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:59:26 by seyang            #+#    #+#             */
/*   Updated: 2023/02/21 18:08:42 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_first_pipe(t_child *child, t_node *curr)
{
	if (curr != 0)
		redirect_pipe(child, curr, 0, 0);
	else if (child->cmd[child->launch_cnt + 1] != 0)
	{
		if (dup2(child->fd[child->launch_cnt][P_WRITE], STDOUT_FILENO) \
			== -1)
			exit(-1);
		close(child->fd[child->launch_cnt][P_WRITE]);
		close(child->fd[child->launch_cnt][P_READ]);
	}
}

void	set_end_pipe(t_child *child, t_node *curr)
{
	if (curr != 0)
		redirect_pipe(child, curr, 0, 0);
	else
	{
		if (dup2(child->fd[child->launch_cnt - 1][P_READ], STDIN_FILENO) \
			== -1)
			exit (-1);
		close(child->fd[child->launch_cnt - 1][P_READ]);
		close(child->fd[child->launch_cnt][P_WRITE]);
		close(child->fd[child->launch_cnt][P_READ]);
	}
}

void	set_middle_pipe(t_child *child, t_node *curr)
{
	if (curr != 0)
		redirect_pipe(child, curr, 0, 0);
	else
	{
		if (dup2(child->fd[child->launch_cnt - 1][P_READ], STDIN_FILENO) \
			== -1)
			exit (-1);
		close(child->fd[child->launch_cnt - 1][P_READ]);
		if (dup2(child->fd[child->launch_cnt][P_WRITE], STDOUT_FILENO) \
			== -1)
			exit(-1);
		close(child->fd[child->launch_cnt][P_WRITE]);
		close(child->fd[child->launch_cnt][P_READ]);
	}
}
