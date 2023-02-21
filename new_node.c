/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:46:35 by seyang            #+#    #+#             */
/*   Updated: 2023/02/20 19:46:53 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node_inf	*new_node_inf(void)
{
	t_node_inf	*new_inf;

	new_inf = ft_malloc(sizeof(t_node_inf));
	new_inf->head = NULL;
	new_inf->tail = NULL;
	return (new_inf);
}

t_node	*new_node(char *arr)
{
	t_node	*new_node;

	new_node = ft_malloc(sizeof(t_node));
	new_node->arr = arr;
	new_node->check_malloc = 1;
	new_node->check_adhere_back = 0;
	new_node->is_file = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
