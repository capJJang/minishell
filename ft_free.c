/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:52:24 by seyang            #+#    #+#             */
/*   Updated: 2023/01/09 13:04:48 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_free_3d(char ***arr)
{
	int	i;

	i = 0;
	while (arr[i])
		ft_free_2d(arr[i++]);
	free(arr);
}

void	ft_free(t_node_inf *node_inf)
{
	t_node	*curr;
	t_node	*next;

	curr = node_inf->head;
	node_inf->tail->next = 0;
	while (curr)
	{
		next = curr->next;
		// if (curr->check_malloc == 1)
		// 	free(curr->arr);
		free(curr);
		curr = next;
	}
	free(node_inf);
}