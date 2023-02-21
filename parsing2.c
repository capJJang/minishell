/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:33:42 by seyang            #+#    #+#             */
/*   Updated: 2023/02/20 19:36:59 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing_pipe(t_node_inf *node_inf, char *read_line)
{
	int		start;
	int		finish;
	char	*arr;

	start = 0;
	finish = 0;
	while (read_line[finish])
	{
		finish = ft_find_after_chr(read_line, start, '|');
		if (finish - start == 0)
		{
			arr = ft_calloc(sizeof(char), 2);
			arr[0] = '|';
			add_back_node(node_inf, new_node(arr));
			finish = ++start;
			continue ;
		}
		arr = ft_substr(read_line, start, finish - start);
		add_back_node(node_inf, new_node(arr));
		start = finish;
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
}
