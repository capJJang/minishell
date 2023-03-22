/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_to_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:49:41 by seyang            #+#    #+#             */
/*   Updated: 2023/03/19 16:32:44 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sc_free_2(t_node **curr)
{
	char	*temp;

	temp = (*curr)->arr;
	(*curr)->arr = ft_strtrim((*curr)->arr, "\'\"");
	free(temp);
}

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
		while ((node_inf->head && curr->arr[0] != '|') || \
			curr->is_quote_include_pipe)
		{
			size++;
			if (!curr->is_quote_include_pipe && (curr->arr[0] == '<' || \
				curr->arr[0] == '>' || curr->is_file == 1))
				size--;
			if (curr == node_inf->tail)
				break ;
			curr = curr->next;
		}
		cmd[i++] = ft_calloc(sizeof(char *), (size + 2));
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
		if (curr->arr[0] == '|' && !curr->is_quote_include_pipe)
			size++;
		curr = curr->next;
	}
	cmd = ft_malloc(sizeof(char **) * (size + 2));
	cmd[size + 1] = 0;
	new_command2(node_inf, cmd);
	return (cmd);
}

char	***node_to_command(t_node_inf *node_inf)
{
	char	***cmd;

	cmd = new_command(node_inf);
	set_command(cmd, node_inf);
	return (cmd);
}
