/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:37:25 by seyang            #+#    #+#             */
/*   Updated: 2023/03/08 18:56:16 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_back_node(t_node_inf *node_inf, t_node *src_node)
{
	if (node_inf->head == NULL)
	{
		node_inf->head = src_node;
		src_node->next = src_node;
		src_node->prev = src_node;
	}
	else
	{
		src_node->next = node_inf->head;
		src_node->prev = node_inf->tail;
		node_inf->head->prev = src_node;
		node_inf->tail->next = src_node;
	}
	node_inf->tail = src_node;
}

void	add_prev_node(t_node_inf *node_inf, t_node *dst_node, t_node *src_node)
{
	src_node->next = dst_node;
	src_node->prev = dst_node->prev;
	dst_node->prev->next = src_node;
	dst_node->prev = src_node;
	if (dst_node == node_inf->head)
		node_inf->head = src_node;
}

void	add_next_node(t_node_inf *node_inf, t_node *dst_node, t_node *src_node)
{
	src_node->next = dst_node->next;
	src_node->prev = dst_node;
	dst_node->next->prev = src_node;
	dst_node->next = src_node;
	if (dst_node == node_inf->tail)
		node_inf->tail = src_node;
}

void	delete_node(t_node_inf *node_inf, t_node *dst_node)
{
	dst_node->prev->next = dst_node->next;
	dst_node->next->prev = dst_node->prev;
	if (node_inf->head == node_inf->tail)
	{
		node_inf->head = NULL;
		node_inf->tail = NULL;
	}
	else if (node_inf->head == dst_node)
	{
		node_inf->head = dst_node->next;
	}
	else if (node_inf->tail == dst_node)
	{
		node_inf->tail = dst_node->prev;
	}
	free(dst_node->arr);
	free(dst_node);
}

t_node	*find_node(t_node_inf *node_inf, int command_num)
{
	t_node	*curr;

	curr = node_inf->head;
	while (curr->command_num != command_num)
	{
		if (curr == node_inf->tail)
			return (0);
		curr = curr->next;
	}
	return (curr);
}
