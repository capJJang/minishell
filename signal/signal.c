/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:12:54 by segan             #+#    #+#             */
/*   Updated: 2023/02/06 01:24:29 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sigint()
{
	rl_replace_line("", 1);
	printf("\b\b  \n");
	rl_on_new_line();
	rl_redisplay();
}

void	init_signal()
{
	signal(SIGINT, sigint);
	signal(SIGQUIT, SIG_IGN);
}
