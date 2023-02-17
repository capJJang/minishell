/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:50:26 by seyang            #+#    #+#             */
/*   Updated: 2023/02/17 18:38:28 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_node(t_node_inf *node_inf)
{
	t_node	*curr;

	curr = node_inf->head;
	printf("%s", "\n\n_________intput_________\n\n");
	while (1)
	{
		printf("%s %d\n", curr->arr, curr->check_adhere_back);
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}

void	print_command(char ***cmd)
{
	int	i;
	int	j;

	i = 0;
	printf("%s", "\n\n_________third level command_________\n\n");
	while (cmd[i])
	{
		j = 0;
		while (cmd[i][j])
		{
			printf("%s\n", cmd[i][j]);
			printf("%d%s", i, "______________\n");
			j++;
		}
		printf("\n");
		i++;
	}
}
