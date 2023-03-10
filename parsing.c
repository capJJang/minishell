/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:53:12 by seyang            #+#    #+#             */
/*   Updated: 2023/03/08 18:55:07 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	line_to_node(t_node_inf *node_inf, char *read_line)
{
	add_back_node(node_inf, new_node(read_line));
	parsing_quote(node_inf);
	parsing_space(node_inf);
	parsing_pipe(node_inf);
	parsing_space(node_inf);
	parsing_redirection(node_inf);
	parsing_space(node_inf);
	parsing_normal_arr(node_inf);
	replace_env(node_inf);
	adhere_some_node(node_inf);
	set_command_num(node_inf);
}

int	check_parse_error(t_node_inf *node_inf)
{
	t_node	*curr;
	int		cmd_cnt;

	if (node_inf->head == NULL)
	{
		add_back_node(node_inf, new_node(ft_strdup("")));
		return (0);
	}
	curr = node_inf->head;
	cmd_cnt = 1;
	while (1)
	{
		while (curr->next->command_num != cmd_cnt || curr != node_inf->tail)
			curr = curr->next;
		if (curr->arr[0] == '<' || curr->arr[0] == '>')
			return (1);
		if (curr == node_inf->tail)
			break ;
	}
	return (0);
}

t_node_inf	*parsing(t_vars *vars, char *read_line)
{
	t_node_inf	*node_inf;

	node_inf = new_node_inf();
	node_inf->vars = vars;
	line_to_node(node_inf, read_line);
	return (node_inf);
}
