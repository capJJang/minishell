/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:53:12 by seyang            #+#    #+#             */
/*   Updated: 2022/12/24 19:12:05 by segan            ###   ########.fr       */
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
			arr = ft_calloc(sizeof(char), 1);
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
			if (curr == node_inf->tail) // 20221216 seyang : add : if only one word
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

void	parsing_quote(t_node_inf *node_inf)
{
	t_node	*curr;
	char	*temp;
	char	c;
	int		start;
	int		finish;

	curr = node_inf->head;
	while (1)
	{
		start = 0;
		while (1)
		{
			c = set_single_or_double(curr->arr, 0);
			if (c == 0 || c == -1)
				break ;
			start = ft_find_after_chr(curr->arr, start, c);
			finish = ft_find_after_chr(curr->arr, start + 1, c);
			if (curr->arr[finish + 1] == 0) // 20221216 seyang : add
			 	break ;
			temp = curr->arr;
			if (start != 0)
			{
				finish = start - 1;
				start = 0;
			}
			add_prev_node(node_inf, curr, new_node(ft_substr(curr->arr, start, finish + 1)));
			curr->arr = ft_substr(curr->arr, finish + 1, ft_strlen(curr->arr) - finish);
			free(temp);
		}
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}

void	line_to_node(t_node_inf *node_inf, char *read_line)
{
	parsing_pipe(node_inf, read_line);
	parsing_space(node_inf);
	parsing_command(node_inf);
	parsing_space(node_inf);
	parsing_quote(node_inf);
	parsing_space(node_inf);
}

t_node_inf	*parsing(char *read_line)
{
	t_node_inf	*node_inf;

	if (is_empty_line(read_line))
		return (EMPTY_LINE);
	node_inf = new_node_inf();
	line_to_node(node_inf, read_line);
	free(read_line);
	return (node_inf);
}
