/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_to_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:49:41 by seyang            #+#    #+#             */
/*   Updated: 2022/12/16 18:01:01 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_command2(t_node_inf *node_inf, char ***command)
{
	t_node	*curr;
	int		size;
	int		i;

	curr = node_inf->head;
	i = 0;
	while (1)
	{
		size = 0;
		while (curr->arr[0] != '|')
		{
			size++;
			if (curr == node_inf->tail)
				break ;
			curr = curr->next;
		}
		command[i] = ft_malloc(sizeof(char *) * (size + 2));
		command[i][size] = 0;
		command[i++][size] = 0;
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}

char	***new_command(t_node_inf *node_inf)
{
	char	***command;
	t_node	*curr;
	int		size;

	curr = node_inf->head;
	size = 0;
	while (1)
	{
		if (curr == node_inf->tail)
			break ;
		if (curr->arr[0] == '|')
			size++;
		curr = curr->next;
	}
	command = ft_malloc(sizeof(char **) * (size + 2));
	command[size + 1] = 0;
	new_command2(node_inf, command);
	return (command);
}

void	set_command(char ***command, t_node_inf *node_inf)
{
	t_node	*curr;
	int		i;
	int		j;

	curr = node_inf->head;
	i = 0;
	while (1)
	{
		j = 0;
		while (curr->arr[0] != '|')
		{
			command[i][j++] = curr->arr;
			if (curr == node_inf->tail)
				break ;
			curr = curr->next;
		}
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
		i++;
	}
}

char	***node_to_command(t_node_inf *node_inf)
{
	char	***command;

	command = new_command(node_inf);
	set_command(command, node_inf);
	return (command);
}
