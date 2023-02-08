/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:29:50 by seyang            #+#    #+#             */
/*   Updated: 2023/02/08 18:30:14 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*is_redirection(t_child child)
{
	t_node	*curr;

	curr = find_node(child.node_inf, child.launch_cnt + 1);
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

void	redirect_pipe(t_child child, t_node *curr, int *check_error)
{
	int		fd;
	bool	in;
	bool	out;
	char	*get_line;

	while (curr != 0)
	{
		if (ft_strncmp(curr->prev->arr, ">", 2) == 0)
		{
			fd = open(curr->arr, O_TRUNC | O_WRONLY);
			if (fd == -1)
				print_errno_in_child(curr->arr);
			*check_error += dup2(fd, STDOUT_FILENO);
			close(fd);
			// close(child.fd[child.launch_cnt][P_WRITE]);
			if (out == false)
				out = true;
		}
		else if (ft_strncmp(curr->prev->arr, "<", 2) == 0)
		{
			fd = open(curr->arr, O_RDONLY);
			if (fd == -1)
				print_errno_in_child(curr->arr);
			*check_error = dup2(fd, STDIN_FILENO);
			close(fd);
			// close(child.fd[child.launch_cnt][P_READ]);
			if (in == false)
				in = true;
		}
		else if (ft_strncmp(curr->prev->arr, "<<", 3) == 0)
		{
			int	temp_fd = open("*&$@^857sdf{}.:<<12#@", O_CREAT | O_WRONLY | O_TRUNC, 0644);
			while (1)
			{
				write(STDOUT_FILENO, "> ", 2);
				get_line = get_next_line(STDIN_FILENO);
				if (ft_strlen(get_line) - 1 != 0 \
					&& ft_strncmp(get_line, curr->arr, ft_strlen(curr->arr)) == 0 \
					&& (ft_strlen(get_line) - 1 == ft_strlen(curr->arr)))
					break ;
				write(temp_fd, get_line, ft_strlen(get_line));
				free (get_line);
			}
			free (get_line);
			close (temp_fd);
			temp_fd = open("*&$@^857sdf{}.:<<12#@", O_RDONLY);
			*check_error += dup2(temp_fd, STDIN_FILENO);
			unlink("*&$@^857sdf{}.:<<12#@");
			close(temp_fd);
			if (in == false)
				in = true;
		}
		else if (ft_strncmp(curr->prev->arr, ">>", 3) == 0)
		{
			fd = open(curr->arr, O_APPEND | O_WRONLY);
			if (fd == -1)
				print_errno_in_child(curr->arr);
			*check_error += dup2(fd, STDOUT_FILENO);
			close(fd);
			// close(child.fd[child.launch_cnt][P_WRITE]);
			if (out == false)
				out = true;
		}
		curr->is_file = 0;
		curr = is_redirection(child);
	}
	if (in == true)
		close(child.fd[child.launch_cnt][P_READ]);
	if (out == true)
		close(child.fd[child.launch_cnt][P_WRITE]);
	if (in == false)
	{
		if (child.launch_cnt > 0)
		{
			*check_error += \
				dup2(child.fd[child.launch_cnt - 1][P_READ], STDIN_FILENO);
			close(child.fd[child.launch_cnt - 1][P_READ]);
		}
	}
	if (out == false && child.cmd[child.launch_cnt + 1] != 0)
	{
		*check_error += \
			dup2(child.fd[child.launch_cnt][P_WRITE], STDOUT_FILENO);
		close(child.fd[child.launch_cnt][P_WRITE]);
	}
}

void	is_child(t_child child)
{
	t_node		*curr;
	int			check_error;

	curr = is_redirection(child);
	check_error = 0;
	if (child.launch_cnt == 0)
	{
		if (curr != 0)
			redirect_pipe(child, curr, &check_error);
		else if (child.cmd[child.launch_cnt + 1] != 0)
		{
			check_error += \
				dup2(child.fd[child.launch_cnt][P_WRITE], STDOUT_FILENO);
			close(child.fd[child.launch_cnt][P_WRITE]);
		}
	}
	else if (child.cmd[child.launch_cnt + 1] == 0)
	{
		if (curr != 0)
			redirect_pipe(child, curr, &check_error);
		else
		{
			check_error += \
				dup2(child.fd[child.launch_cnt - 1][P_READ], STDIN_FILENO);
			close(child.fd[child.launch_cnt - 1][P_READ]);
		}
	}
	else
	{
		if (curr != 0)
			redirect_pipe(child, curr, &check_error);
		else
		{
			check_error += \
				dup2(child.fd[child.launch_cnt - 1][P_READ], STDIN_FILENO);
			close(child.fd[child.launch_cnt - 1][P_READ]);
			check_error += \
				dup2(child.fd[child.launch_cnt][P_WRITE], STDOUT_FILENO);
			close(child.fd[child.launch_cnt][P_WRITE]);
		}
	}
	if (!(check_error < 0) && is_builtin(child.cmd[child.launch_cnt]))
		exe_builtin(child.node_inf);
	else if (check_error < 0 || execve(child.path, \
		child.cmd[child.launch_cnt], child.node_inf->vars->env) == -1)
		print_errno_in_child(0);
}

void	is_parent(pid_t pid)
{
	int	status;

	set_parent_signal();
	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) != 0)
	{
	}
}

int	**new_pipe(char ***cmd)
{
	int	n;
	int	**fd;

	n = 0;
	while (cmd[n])
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

void	execute_command(char **path_env, char ***cmd, t_node_inf *node_inf)
{
	pid_t	pid;
	t_child	child;

	child.fd = new_pipe(cmd);
	child.launch_cnt = 0;
	child.cmd = cmd;
	child.node_inf = node_inf;
	while (cmd[child.launch_cnt])
	{
		node_inf->cmd = cmd[child.launch_cnt];
		child.path = get_path(path_env, cmd[child.launch_cnt][0]);
		if (child.launch_cnt != 0)
			close(child.fd[child.launch_cnt - 1][P_WRITE]);
		if (is_builtin(cmd[child.launch_cnt]) && !ft_node_strncmp(node_inf, "|"))
			exe_builtin(node_inf);
		else
		{
			if (child.path == IS_NOT_FOUND && !is_builtin(cmd[child.launch_cnt]))
			{
				print_cmd_nfound(IS_NOT_FOUND, cmd[child.launch_cnt][0]);
				break ;
			}
			pid = ft_fork();
			if (pid == -1)
				exit (-1);
			if (pid == 0)
				is_child(child);
			else
				is_parent(pid);
		}
		free(child.path);
		child.launch_cnt++;
		child.path = NULL;
	}
	close_pipe(child.fd);
	ft_free_2d((char **)child.fd);
	ft_free_2d(path_env);
}
