/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:44:19 by seyang            #+#    #+#             */
/*   Updated: 2023/03/06 19:56:10 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cut_front(t_node_inf *node_inf, t_node *curr, int start)
{
	char	*temp;

	add_prev_node(node_inf, curr, new_node(ft_substr(curr->arr, 0, start)));
	temp = curr->arr;
	curr->arr = ft_substr(curr->arr, start, ft_strlen(curr->arr) - start);
	free(temp);
	return (2);
}

int	parsing_redirection3(t_node_inf *node_inf, t_node *curr, int end, int start)
{
	char	*temp;

	while (curr->arr[end] && curr->arr[end] != ' ' \
		&& curr->arr[end] != '<' && curr->arr[end] != '>')
		end++;
	if (start == end)
	{
		temp = curr->arr;
		curr->arr = ft_substr(curr->arr, end, ft_strlen(curr->arr) - end);
		free(temp);
		return (CONTINUE);
	}
	add_prev_node(node_inf, curr, \
		new_node(ft_substr(curr->arr, start, end - start)));
	curr->prev->is_file = 1;
	temp = curr->arr;
	while (curr->arr[end] == ' ')
		end++;
	curr->arr = ft_substr(curr->arr, end, ft_strlen(curr->arr) - end);
	free(temp);
	return (0);
}

int	parsing_redirection2(t_node_inf *node_inf, t_node *curr)
{
	int		start;
	int		end;

	start = ft_find_redirection(curr->arr, 0);
	if (curr->arr[start] == 0)
		return (BREAK);
	if (start != 0)
		return (cut_front(node_inf, curr, start));
	end = start;
	while (curr->arr[end] == '<' || curr->arr[end] == '>')
		end++;
	add_prev_node(node_inf, curr, \
		new_node(ft_substr(curr->arr, start, end - start)));
	while (curr->arr[end] == ' ')
		end++;
	start = end;
	if (parsing_redirection3(node_inf, curr, end, start) == CONTINUE)
		return (CONTINUE);
	return (0);
}

void	parsing_redirection(t_node_inf *node_inf)
{
	t_node	*curr;
	int		ret;

	curr = node_inf->head;
	while (1)
	{
		if (curr->arr[0] != '\'' && curr->arr[0] != '\"')
		{
			while (1)
			{
				ret = parsing_redirection2(node_inf, curr);
				if (ret == BREAK)
					break ;
				else if (ret == CONTINUE)
					continue ;
			}
		}
		curr = curr->next;
		if (curr->prev->arr[0] == 0)
			delete_node(node_inf, curr->prev);
		if (curr == node_inf->head)
			break ;
	}
}

void	set_command_num(t_node_inf *node_inf)
{
	t_node	*curr;
	int		command_num;

	command_num = 1;
	curr = node_inf->head;
	while (1)
	{
		curr->command_num = command_num;
		if (curr->arr[0] == '|')
			command_num++;
		curr = curr->next;
		if (curr == node_inf->head)
			break ;
	}
}
