/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:20:37 by segan             #+#    #+#             */
/*   Updated: 2023/03/05 01:15:47 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sigint_readline(int signo)
{
	(void) signo;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

void	sigint_heredoc(int signo)
{
	(void) signo;
	//int	temp_fd;

	printf("\b\b  ");
	//exit(0);
	//temp_fd = open("*&$@^857sdf{}.:<<12#@", O_CREAT | O_WRONLY, 0644);
	//printf("test\n");
	//write(temp_fd, "teset", 1);
	//close(temp_fd);
}
