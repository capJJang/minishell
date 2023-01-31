/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 02:44:57 by segan             #+#    #+#             */
/*   Updated: 2023/01/30 17:44:36 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_exit(t_node_inf *node_inf)
{
	int		argc;
	int		exit_status;
	int		i;

	i = 0;
	exit_status = 0;
	argc = ft_strlen_2d(node_inf->cmd);
	printf("exit\n");
	if (argc < 2)
		exit(exit_status);
	while (node_inf->cmd[1][i])
	{
		if (ft_isdigit(node_inf->cmd[1][i++]))
			continue ;
		printf("bash: exit: %s: numeric argumnet required\n", node_inf->cmd[1]);
		exit(255);
	}
	if (argc > 2)
	{
		printf("bash: exit: too many arguments\n");
		*node_inf->vars->stat = 1;
	}
	else
		exit(ft_atoi(node_inf->cmd[1]));
}
