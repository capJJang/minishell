/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:59:26 by seyang            #+#    #+#             */
/*   Updated: 2023/02/24 19:35:10 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_first_pipe(t_child *child, t_node *curr, int size)
{
	int	i;

	i = 0;
	if (curr != 0)
		redirect_pipe(child, curr, false);
	else if (child->cmd[child->launch_cnt + 1] != 0)
	{
		if (dup2(child->fd[child->launch_cnt][P_WRITE], STDOUT_FILENO) \
			== -1)
			exit(-1);
	}
	while (i < size - 1)
	{
		close(child->fd[i][P_READ]);
		if (i != 0)
			close(child->fd[i][P_WRITE]);
		i++;
	}
}

void	set_end_pipe(t_child *child, t_node *curr, int size)
{
	int	i;

	i = 0;
	if (curr != 0)
		redirect_pipe(child, curr, false);
	else
	{
		if (dup2(child->fd[child->launch_cnt - 1][P_READ], STDIN_FILENO) \
			== -1)
			exit (-1);
	}
	while (i < size - 1)
	{
		if (i != child->launch_cnt - 1)
			close(child->fd[i][P_READ]);
		close(child->fd[i][P_WRITE]);
		i++;
	}
}

void	set_middle_pipe(t_child *child, t_node *curr, int size)
{
	int	i;

	i = 0;
	if (curr != 0)
		redirect_pipe(child, curr, false);
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
	}
	while (i < size - 1)
	{
		if (i != child->launch_cnt - 1)
			close(child->fd[i][P_READ]);
		if (i != child->launch_cnt)
			close(child->fd[i][P_WRITE]);
		i++;
	}
}

void	child_heredoc(t_child *child)
{
	int	temp_fd;

	temp_fd = open("*&$@^857sdf{}.:<<12#@", O_RDONLY);
	if (!is_builtin(child->cmd[child->launch_cnt]))
		if (dup2(temp_fd, STDIN_FILENO) == -1)
			exit (-1);
	close(temp_fd);
}

t_node	*is_redirection22(t_child child)
{
	t_node	*curr;

	curr = find_node(child.node_inf, child.launch_cnt + 1);
	if (curr == NULL)
		return (NULL);
	while (1)
	{
		if (curr->is_file == 1 || curr->is_file == 2)
			return (curr);
		if (curr->command_num != curr->next->command_num \
			|| curr == child.node_inf->tail)
			break ;
		curr = curr->next;
	}
	return (0);
}
