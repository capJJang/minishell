/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:48:57 by seyang            #+#    #+#             */
/*   Updated: 2023/03/19 17:50:34 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*is_all_redirection2(t_child child)
{
	t_node	*curr;

	curr = child.node_inf->head;
	while (1)
	{
		if (curr->is_file == 1)
			return (curr);
		if (curr == child.node_inf->tail)
			break ;
		curr = curr->next;
	}
	return (0);
}
