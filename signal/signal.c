/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:12:54 by segan             #+#    #+#             */
/*   Updated: 2023/02/02 17:49:32 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sigint()
{
	printf("\n");
	return ;
}

void	sigquit()
{
	write(1, "\b\b", 2);
	return ;
}

void	init_signal(void)
{
	signal(SIGINT, sigint);
	signal(SIGQUIT, sigquit);
}
