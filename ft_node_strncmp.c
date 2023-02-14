/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:18:10 by segan             #+#    #+#             */
/*   Updated: 2023/02/14 11:48:59 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_node_strncmp(t_node_inf *node_inf, const char *s2)
{
	t_node	*temp;

	temp = node_inf->head;
	while (1)
	{
		if (!ft_strncmp(temp->arr, s2, ft_strlen(s2)))
			return (1);
		if (temp == node_inf->tail)
			break ;
		temp = temp->next;
	}
	return (0);
}
