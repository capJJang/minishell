/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:33:42 by seyang            #+#    #+#             */
/*   Updated: 2023/03/19 16:03:28 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing_pipe(t_node_inf *node_inf)
{
	int		finish;
	char	*temp;
	t_node	*curr;

	curr = node_inf->head;
	while (1)
	{
		finish = 0;
		if (curr->arr[0] != '\'' && curr->arr[0] != '\"')
		{
			while (curr->arr[finish])
			{
				finish = ft_find_after_chr(curr->arr, 0, '|');
				finish += (finish == 0);
				add_next_node(node_inf, curr, new_node(ft_substr(curr->arr, \
					finish, strlen(curr->arr) - finish)));
				temp = curr->arr;
				curr->arr = ft_substr(curr->arr, 0, finish);
				free(temp);
			}
		}
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}

void	parsing_space(t_node_inf *node_inf)
{
	t_node	*curr;
	char	*temp;

	curr = node_inf->head;
	while (1)
	{
		temp = curr->arr;
		curr->arr = ft_strtrim(curr->arr, " ");
		free(temp);
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}

void	parsing_command(t_node_inf *node_inf)
{
	t_node	*curr;
	char	*temp;
	int		i;

	curr = node_inf->head;
	while (1)
	{
		i = ft_find_after_chr(curr->arr, 0, ' ');
		if (curr->arr[i] == 0)
		{
			if (curr == node_inf->tail)
				break ;
			curr = curr->next;
			continue ;
		}
		temp = curr->arr;
		add_prev_node(node_inf, curr, new_node(ft_substr(curr->arr, 0, i)));
		curr->arr = ft_substr(curr->arr, i + 1, ft_strlen(curr->arr) - i);
		free(temp);
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}

void	check_adhere(t_node *curr, int end)
{
	if (curr->arr[end] != '\'' && curr->arr[end] != '\"' \
		&& curr->arr[end] != '$')
	{
		if (curr->arr[end] != ' ')
			curr->prev->check_adhere_back = 1;
	}
	else
	{
		if (curr->arr[end + 1] != ' ')
			curr->prev->check_adhere_back = 1;
	}
	while (end != 0 && curr->arr[end] == ' ')
		end--;
	if (curr->arr[end] == '<' || curr->arr[end] == '>')
		curr->is_file = 1;
}
