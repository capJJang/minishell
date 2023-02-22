/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:59:18 by seyang            #+#    #+#             */
/*   Updated: 2023/02/21 18:47:17 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*is_redirection(t_child child)
{
	t_node	*curr;

	curr = find_node(child.node_inf, child.launch_cnt + 1);
	if (curr == NULL)
		return (NULL);
	while (1)
	{
		if (curr->is_file == 1)
			return (curr);
		if (curr->command_num != curr->next->command_num \
			|| curr == child.node_inf->tail)
			break ;
		curr = curr->next;
	}
	return (0);
}

void	redirect_outfile(t_node *curr, bool *out)
{
	int	fd;

	fd = open(curr->arr, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		print_errno_in_child(curr->arr);
	if (dup2(fd, STDOUT_FILENO) == -1)
		exit(-1);
	close(fd);
	if (*out == false)
		*out = true;
}

void	redirect_infile(t_node *curr, bool *in, t_node_inf *node_inf)
{
	int	fd;

	fd = open(curr->arr, O_RDONLY);
	if (fd == -1)
	{
		if (!(is_redirection2(node_inf) && ft_node_strncmp(node_inf, "|")))
			print_errno_in_child(curr->arr);
		else
		{
			print_cmd_nfound(2, curr->arr);
			return ;
		}
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		exit(-1);
	close(fd);
	if (*in == false)
		*in = true;
}

void	rollback_std_fd(t_node_inf *node_inf, int *fd_in, int *fd_out)
{
	if (is_redirection2(node_inf) && ft_node_strncmp(node_inf, "|"))
	{
		if (dup2(*fd_in, STDIN_FILENO) == -1)
			exit (-1);
		close(*fd_in);
		if (dup2(*fd_out, STDOUT_FILENO) == -1)
			exit (-1);
		close(*fd_out);
	}
}
