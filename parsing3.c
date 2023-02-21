/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:39:19 by seyang            #+#    #+#             */
/*   Updated: 2023/02/20 19:39:26 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parsing2_quito(t_node_inf *node_inf, t_node *curr, int start)
{
	char	*temp;
	char	c;
	int		end;

	c = set_single_or_double(curr->arr, 0);
	if (c == 0 || c == -1)
		return (BREAK);
	start = ft_find_after_chr(curr->arr, start, c);
	end = ft_find_after_chr(curr->arr, start + 1, c);
	if (start == 0 && curr->arr[end + 1] == 0)
		return (BREAK);
	temp = curr->arr;
	if (start != 0)
	{
		end = start - 1;
		start = 0;
	}
	add_prev_node(node_inf, curr, \
		new_node(ft_substr(curr->arr, start, end + 1)));
	check_adhere(curr, end);
	curr->arr = ft_substr(curr->arr, end + 1, ft_strlen(curr->arr) - end);
	free(temp);
	return (0);
}

void	parsing_quote(t_node_inf *node_inf)
{
	t_node	*curr;
	int		start;

	curr = node_inf->head;
	while (1)
	{
		start = 0;
		while (1)
			if (parsing2_quito(node_inf, curr, start) == BREAK)
				break ;
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}

void	set_normal_arr(t_node_inf *node_inf, t_node **curr, char *arr)
{
	t_node	*temp;
	int		start;
	int		end;

	start = 0;
	while (1)
	{
		end = ft_find_after_chr(arr, start, ' ');
		add_prev_node(node_inf, *curr, \
			new_node(ft_substr(arr, start, end - start)));
		while (arr[end] == ' ')
			end++;
		if (arr[end] == 0)
			break ;
		start = end;
	}
	if ((*curr)->check_adhere_back == 1)
		(*curr)->prev->check_adhere_back = 1;
	if ((*curr)->is_file == 1)
		(*curr)->prev->is_file = 1;
	temp = *curr;
	*curr = (*curr)->next;
	delete_node(node_inf, temp);
}

void	parsing_normal_arr(t_node_inf *node_inf)
{
	t_node	*curr;

	curr = node_inf->head;
	while (1)
	{
		if (curr->arr[0] != '\'' && curr->arr[0] != '\"')
			set_normal_arr(node_inf, &curr, curr->arr);
		else
			curr = curr->next;
		if (curr == node_inf->head || node_inf->head == node_inf->tail)
			break ;
	}
}
