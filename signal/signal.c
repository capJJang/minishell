/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:12:54 by segan             #+#    #+#             */
/*   Updated: 2023/02/07 19:14:22 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sigint()
{
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

void	init_signal()
{
	signal(SIGINT, sigint);
	signal(SIGQUIT, SIG_IGN);
}

//void	set_siganl_heredoc(pid_t pid)
//{
//	if (pid == 0)
//	{
//		signal()
//	}
//	else
//}

//void	set_signal_

/*
case : cat
	\ : ^\Quti :3		exit status : 131
	c : ^C				exit status : 130
	d :					exit status : 0

case : <<
	\ : (SIG_IGN)
	c : ^C				exit status : 1
	d :	(no newline)	exit status : 0
*/
