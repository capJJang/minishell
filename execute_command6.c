/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:25:56 by seyang            #+#    #+#             */
/*   Updated: 2023/03/19 16:56:47 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*is_redirection222(t_child child)
{
	t_node	*curr;

	curr = find_node(child.node_inf, child.launch_cnt + 1);
	if (curr == NULL)
		return (NULL);
	while (1)
	{
		if (curr->is_file >= 1 && curr->is_file != 2)
			return (curr);
		if (curr->command_num != curr->next->command_num \
			|| curr == child.node_inf->tail)
			break ;
		curr = curr->next;
	}
	return (0);
}

void	redirect_pipe2(t_child *child, t_node *curr, bool check)
{
	bool				in;
	bool				out;
	extern sig_atomic_t	g_heredoc_stat;
	struct termios		original_term;

	tcgetattr(0, &original_term);
	while (curr != 0 && g_heredoc_stat >= 1)
	{
		if (ft_strncmp(curr->prev->arr, ">", 2) == 0 && !check)
			redirect_outfile(curr, &out);
		else if (ft_strncmp(curr->prev->arr, "<", 2) == 0 && !check)
			redirect_infile(curr, &in, child->node_inf);
		else if (ft_strncmp(curr->prev->arr, ">>", 3) == 0 && !check)
			append_file(curr, &out);
		curr->is_file = 2;
		curr = is_redirection222(*child);
	}
	if (check == false)
		close_fd(in, out, *child);
}

int	is_redirection23(t_node_inf *node_inf)
{
	if (!ft_node_strncmp(node_inf, "<"))
		return (1);
	if (!ft_node_strncmp(node_inf, ">"))
		return (1);
	if (!ft_node_strncmp(node_inf, ">>"))
		return (1);
	return (0);
}

void	heredoc_child(char *get_line, t_node *curr, int temp_fd)
{
	set_heredoc_signal();
	get_line = readline("> ");
	get_line = ft_strjoin2(get_line, "\n", 1, 0);
	if (get_line == EMPTY_LINE || get_line[0] == 0)
		exit(2);
	if (is_break(get_line, curr) == BREAK)
		exit(0);
	write(temp_fd, get_line, ft_strlen(get_line));
	free(get_line);
}

void	reset_stat(struct termios original_term)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &original_term);
	restore_signal();
}
