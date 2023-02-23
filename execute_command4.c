/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:59:26 by seyang            #+#    #+#             */
/*   Updated: 2023/02/23 15:50:38 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_first_pipe(t_child *child, t_node *curr, int size)
{
	int	i;

	i = 0;
	if (curr != 0)
		redirect_pipe(child, curr, 0, 0);
	else if (child->cmd[child->launch_cnt + 1] != 0)
	{
		if (dup2(child->fd[child->launch_cnt][P_WRITE], STDOUT_FILENO) \
			== -1)
			exit(-1);
		while (i < size - 1)
		{
			close(child->fd[i][P_READ]);
			if (i != 0)
				close(child->fd[i][P_WRITE]);
			i++;
		}
	}
}

void	set_end_pipe(t_child *child, t_node *curr, int size)
{
	int	i;

	i = 0;
	if (curr != 0)
		redirect_pipe(child, curr, 0, 0);
	else
	{
		if (dup2(child->fd[child->launch_cnt - 1][P_READ], STDIN_FILENO) \
			== -1)
			exit (-1);
		while (i < size - 1)
		{
			if (i != child->launch_cnt - 1)
				close(child->fd[i][P_READ]);
			close(child->fd[i][P_WRITE]);
			i++;
		}
	}
}

void	set_middle_pipe(t_child *child, t_node *curr, int size)
{
	int	i;

	i = 0;
	if (curr != 0)
		redirect_pipe(child, curr, 0, 0);
	else
	{
		if (dup2(child->fd[child->launch_cnt - 1][P_READ], STDIN_FILENO) \
			== -1)
			exit (-1);
		close(child->fd[child->launch_cnt - 1][P_WRITE]);
		if (dup2(child->fd[child->launch_cnt][P_WRITE], STDOUT_FILENO) \
			== -1)
			exit(-1);
		close(child->fd[child->launch_cnt][P_READ]);
		while (i < size - 1)
		{
			if (i != child->launch_cnt - 1)
				close(child->fd[i][P_READ]);
			if (i != child->launch_cnt)
				close(child->fd[i][P_WRITE]);
			i++;
		}
	}
}
//			0				1
// cat		|		cat		|		ls
//0				1				2
