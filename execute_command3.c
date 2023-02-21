/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:59:22 by seyang            #+#    #+#             */
/*   Updated: 2023/02/21 14:29:52 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_break(char *get_line, t_node *curr)
{
	if (get_line == EMPTY_LINE)
		return (BREAK);
	if (ft_strlen(get_line) - 1 != 0 \
		&& ft_strncmp(get_line, curr->arr, ft_strlen(curr->arr)) == 0 \
		&& (ft_strlen(get_line) - 1 == ft_strlen(curr->arr)))
		return (BREAK);
	return (0);
}

void	heredoc(t_node *curr, t_child *child, bool *in)
{
	int		temp_fd;
	char	*get_line;

	set_heredoc_signal();
	temp_fd = open("*&$@^857sdf{}.:<<12#@", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		get_line = get_next_line(STDIN_FILENO);
		if (is_break(get_line, curr) == BREAK)
			break ;
		write(temp_fd, get_line, ft_strlen(get_line));
		free (get_line);
	}
	free (get_line);
	close (temp_fd);
	temp_fd = open("*&$@^857sdf{}.:<<12#@", O_RDONLY);
	if (!is_builtin(child->cmd[child->launch_cnt]))
		if (dup2(temp_fd, STDIN_FILENO) == -1)
			exit (-1);
	unlink("*&$@^857sdf{}.:<<12#@");
	close(temp_fd);
	if (*in == false)
		*in = true;
}

void	append_file(t_node *curr, bool *out)
{
	int	fd;

	fd = open(curr->arr, O_APPEND | O_WRONLY);
	if (fd == -1)
		print_errno_in_child(curr->arr);
	if (dup2(fd, STDOUT_FILENO) == -1)
		exit(-1);
	close(fd);
	if (*out == false)
		*out = true;
}

void	close_fd(bool in, bool out, t_child child)
{
	if (in == true)
		close(child.fd[child.launch_cnt][P_READ]);
	if (out == true)
		close(child.fd[child.launch_cnt][P_WRITE]);
	if (in == false)
	{
		if (child.launch_cnt > 0)
		{
			if (dup2(child.fd[child.launch_cnt - 1][P_READ], STDIN_FILENO) \
				== -1)
				exit(-1);
			close(child.fd[child.launch_cnt - 1][P_READ]);
			close(child.fd[child.launch_cnt][P_READ]);
		}
	}
	if (out == false && child.cmd[child.launch_cnt + 1] != 0)
	{
		if (dup2(child.fd[child.launch_cnt][P_WRITE], STDOUT_FILENO) == -1)
			exit(-1);
		close(child.fd[child.launch_cnt][P_WRITE]);
	}
}

int	redirect_pipe(t_child *child, t_node *curr, bool is_parent)
{
	bool	in;
	bool	out;
	int		fd;

	if (is_parent)
		fd = dup(STDIN_FILENO);
	while (curr != 0)
	{
		if (ft_strncmp(curr->prev->arr, ">", 2) == 0)
			redirect_outfile(curr, &out);
		else if (ft_strncmp(curr->prev->arr, "<", 2) == 0)
			redirect_infile(curr, &in);
		else if (ft_strncmp(curr->prev->arr, "<<", 3) == 0)
			heredoc(curr, child, &in);
		else if (ft_strncmp(curr->prev->arr, ">>", 3) == 0)
			append_file(curr, &out);
		curr->is_file = 0;
		curr = is_redirection(*child);
	}
	close_fd(in, out, *child);
	if (is_parent)
		return (fd);
	return (0);
}
