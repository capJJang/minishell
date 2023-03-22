/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_to_command2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:10:54 by seyang            #+#    #+#             */
/*   Updated: 2023/03/19 17:05:50 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_redirection(t_node_inf *node_inf, t_node **curr)
{
	while (((*curr)->arr[0] == '<' \
		|| (*curr)->arr[0] == '>' || (*curr)->is_file == 1) \
		&& (*curr)->is_quote_include_pipe == 0)
	{
		if ((*curr) == node_inf->tail)
			return (R_RETURN);
		(*curr) = (*curr)->next;
	}
	return (0);
}

void	set_command3(int *end, t_node **curr)
{
	*end = 0;
	while ((*curr)->arr[*end])
		(*end)++;
	(*end)--;
}

int	is_quote(char *arr, int end)
{
	if ((arr[0] == '\'' && arr[end] == '\'') \
		|| (arr[0] == '\"' && arr[end] == '\"'))
		return (1);
	return (0);
}

int	set_command2(t_node **curr, t_node_inf *node_inf, char ***cmd, int i)
{
	int		j;
	int		end;

	j = 0;
	while ((*curr)->arr[0] != '|' || (*curr)->is_quote_include_pipe != 0)
	{
		if (skip_redirection(node_inf, curr) == R_RETURN)
			return (R_RETURN);
		set_command3(&end, curr);
		if (end >= 2 && is_quote((*curr)->arr, end))
			sc_free_2(curr);
		if ((*curr)->arr[0] == '|' && !(*curr)->is_quote_include_pipe)
			break ;
		if (!(i == 0 && (*curr)->arr[0] == '|') \
			|| (*curr)->is_quote_include_pipe)
			cmd[i][j++] = (*curr)->arr;
		if ((*curr) == node_inf->tail)
			break ;
		(*curr) = (*curr)->next;
		if (skip_redirection(node_inf, curr) == R_RETURN)
			return (R_RETURN);
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
