/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:26:22 by segan             #+#    #+#             */
/*   Updated: 2023/02/17 19:13:01 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_echo(t_node_inf *node_inf)
{
	int		new_line;
	int		i;

	i = 1;
	new_line = 1;
	if (!ft_strncmp(node_inf->cmd[i], "-n", 3))
	{
		i = 2;
		new_line = 0;
	}
	while (node_inf->cmd[i])
	{
		printf("%s", node_inf->cmd[i++]);
		if (node_inf->cmd[i] == 0)
			break ;
		printf(" ");
	}
	if (new_line)
		printf("\n");
	*node_inf->vars->stat = 0;
}
