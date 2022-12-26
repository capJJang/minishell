/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:52:24 by seyang            #+#    #+#             */
/*   Updated: 2022/12/27 03:03:30 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node_inf	*free_node_inf(t_node_inf *node_inf)
{
	t_node	*to_be_freed;
	t_node	*curr;

	curr = node_inf->head;
	while (curr)
	{
		to_be_freed = curr;
		curr = curr->next;
		if (curr == node_inf->head)
			break ;
		free(to_be_freed);
		to_be_freed = NULL;
	}
	free(node_inf);
	return (0);
}

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
