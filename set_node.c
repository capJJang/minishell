/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:37:25 by seyang            #+#    #+#             */
/*   Updated: 2022/12/28 15:33:14 by segan            ###   ########.fr       */
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
	new_node->check_adhere_back = 0;
	new_node->is_file = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

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