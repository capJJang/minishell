/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:12:54 by segan             #+#    #+#             */
/*   Updated: 2023/03/03 18:56:41 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_readline_signal(void)
{
	extern int	rl_catch_signals;

	rl_catch_signals = 0;
	signal(SIGINT, sigint_readline);
	signal(SIGQUIT, SIG_IGN);
}

void	restore_signal(void)
{
	extern int	rl_catch_signals;

	rl_catch_signals = 1;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	set_parent_signal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	set_heredoc_signal(void)
{
	extern int	rl_catch_signals;

	rl_catch_signals = 0;
	signal(SIGINT, sigint_heredoc);
	signal(SIGQUIT, SIG_IGN);
}

void	set_parent_heredoc_signal(void)
{
	extern int	rl_catch_signals;

	rl_catch_signals = 0;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
