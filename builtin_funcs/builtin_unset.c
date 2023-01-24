/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:53:02 by segan             #+#    #+#             */
/*   Updated: 2023/01/24 17:31:07 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_unset(t_node_inf *node_inf)
{
	t_node	*curr;

	curr = node_inf->head->next;
	while (curr != node_inf->head)
	{
		ft_unset_env(node_inf->vars, node_inf->head->next->arr);
		ft_unset_sh_var(node_inf->vars, node_inf->head->next->arr);
		curr = curr->next;
	}
}
