/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:05:58 by segan             #+#    #+#             */
/*   Updated: 2023/02/09 21:29:47 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	ft_fork(void)
{
	pid_t	pid;

		printf("parent: %d\n", getpid());
	pid = fork();
	if (pid == 0)
		printf("child: %d\n", getpid());
	if (pid == -1)
		exit(-1);
	return (pid);
}
