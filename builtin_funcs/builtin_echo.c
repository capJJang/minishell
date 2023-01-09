/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:26:22 by segan             #+#    #+#             */
/*   Updated: 2023/01/09 15:32:58 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_echo(t_node_inf *node_inf)
{
	int		new_line;
	t_node	*temp;

	temp = node_inf->head;
	new_line = 1;
	if (!ft_strncmp(temp->next->arr, "-n", 2))
	{
		new_line = 0;
		temp = temp->next;
	}
	if (temp != temp->next)
		printf("%s", temp->next->arr);
	if (new_line)
		printf("\n");
}
