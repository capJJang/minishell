/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:52:24 by seyang            #+#    #+#             */
/*   Updated: 2022/12/25 07:15:48 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node_inf	*free_node_inf(t_node_inf *node_inf)
{
	free(node_inf->head);
	if (node_inf->head != node_inf->tail)
		free(node_inf->tail);
	free(node_inf);
	node_inf = NULL;
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
