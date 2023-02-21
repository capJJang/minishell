/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_to_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:49:41 by seyang            #+#    #+#             */
/*   Updated: 2023/02/20 19:32:50 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_command2(t_node_inf *node_inf, char ***cmd)
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
			if (curr->arr[0] == '<' || \
				curr->arr[0] == '>' || curr->is_file == 1)
				size--;
			if (curr == node_inf->tail)
				break ;
			curr = curr->next;
		}
		cmd[i] = ft_calloc(sizeof(char *), (size + 2));
		cmd[i++][size + 1] = 0;
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}

char	***new_command(t_node_inf *node_inf)
{
	char	***cmd;
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
	cmd = ft_malloc(sizeof(char **) * (size + 2));
	cmd[size + 1] = 0;
	new_command2(node_inf, cmd);
	return (cmd);
}

int	set_command2(t_node **curr, t_node_inf *node_inf, char ***cmd, int i)
{
	int	j;

	j = 0;
	while ((*curr)->arr[0] != '|')
	{
		while ((*curr)->arr[0] == '<' \
			|| (*curr)->arr[0] == '>' || (*curr)->is_file == 1)
		{
			if ((*curr) == node_inf->tail)
				return (R_RETURN);
			(*curr) = (*curr)->next;
		}
		cmd[i][j++] = (*curr)->arr;
		if ((*curr) == node_inf->tail)
			break ;
		(*curr) = (*curr)->next;
		while ((*curr)->arr[0] == '<' \
			|| (*curr)->arr[0] == '>' || (*curr)->is_file == 1)
		{
			if ((*curr) == node_inf->tail)
				return (R_RETURN);
			(*curr) = (*curr)->next;
		}
	}
	return (0);
}

void	set_command(char ***cmd, t_node_inf *node_inf)
{
	t_node	*curr;
	int		i;
	int		ret;

	curr = node_inf->head;
	i = 0;
	while (1)
	{
		ret = set_command2(&curr, node_inf, cmd, i);
		if (ret == R_RETURN)
			return ;
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
		i++;
	}
}

char	***node_to_command(t_node_inf *node_inf)
{
	char	***cmd;

	cmd = new_command(node_inf);
	set_command(cmd, node_inf);
	return (cmd);
}
