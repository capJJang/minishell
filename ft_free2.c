/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:15:35 by seyang            #+#    #+#             */
/*   Updated: 2023/03/16 16:42:33 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing_env_free(char *env, char *arr)
{
	free(env);
	free(arr);
}

void	ft_syntax_free(t_node_inf *node_inf)
{
	t_node	*curr;
	t_node	*next;

	curr = node_inf->head;
	while (1)
	{
		next = curr->next;
		free(curr->arr);
		free(curr);
		curr = next;
		if (curr == node_inf->head)
			break ;
	}
	free(node_inf);
}
