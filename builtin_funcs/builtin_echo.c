/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:26:22 by segan             #+#    #+#             */
/*   Updated: 2023/02/08 20:39:47 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_echo(t_node_inf *node_inf)
{
	int		new_line;
	int		i;

	i = 1;
	new_line = 1;
	printf("test: %s\n", node_inf->cmd[i]);
	if (!ft_strncmp(node_inf->cmd[i], "-n", ft_strlen(node_inf->cmd[i])))
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
