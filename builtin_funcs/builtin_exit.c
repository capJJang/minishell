/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 02:44:57 by segan             #+#    #+#             */
/*   Updated: 2023/01/12 18:28:46 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_exit(t_node_inf *node_inf)
{
	t_node	*temp;
	int		exit_status;
	int		i;

	i = 0;
	exit_status = 0;
	temp = node_inf->head;
	if (temp != temp->next)
	{
		temp = temp->next;
		while (temp->arr[i])
		{
			if (ft_isdigit(temp->arr[i++]))
				continue ;
			printf("bash: %s: %s: numeric argumnet required\n", node_inf->head->arr, temp->arr);
			exit(255);
		}
		exit_status = ft_atoi(temp->arr);
	}
	printf("exit\n");
	exit(exit_status);
}
