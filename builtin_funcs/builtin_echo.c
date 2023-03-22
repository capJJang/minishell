/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:26:22 by segan             #+#    #+#             */
/*   Updated: 2023/03/19 15:32:34 by seyang           ###   ########.fr       */
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
		if (write(STDOUT_FILENO, node_inf->cmd[i], \
			ft_strlen(node_inf->cmd[i])) && node_inf->cmd[i + 1] != 0)
			write(STDOUT_FILENO, " ", 1);
		i++;
		if (node_inf->cmd[i] == 0)
			break ;
	}
	if (new_line)
		write(STDOUT_FILENO, "\n", 1);
	*node_inf->vars->stat = 0;
}
