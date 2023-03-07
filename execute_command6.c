/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_comand6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:25:56 by seyang            #+#    #+#             */
/*   Updated: 2023/03/06 21:32:11 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	reset_stat(void)
{
	struct termios		term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	restore_signal();
}
