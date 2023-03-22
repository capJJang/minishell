/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:05:57 by segan             #+#    #+#             */
/*   Updated: 2023/03/19 17:24:25 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_file(t_node_inf *node_inf)
{
	t_node	*curr;

	curr = node_inf->head;
	while (1)
	{
		if (curr->arr[0] == '|' && curr->is_quote_include_pipe != 1)
			free(curr->arr);
		if (ft_strncmp(curr->arr, ">", 2) == 0 \
			&& curr->is_quote_include_pipe != 1)
			free(curr->arr);
		if (ft_strncmp(curr->arr, ">>", 3) == 0 \
			&& curr->is_quote_include_pipe != 1)
			free(curr->arr);
		if (ft_strncmp(curr->arr, "<", 2) == 0 \
			&& curr->is_quote_include_pipe != 1)
			free(curr->arr);
		if (ft_strncmp(curr->arr, "<<", 3) == 0 \
			&& curr->is_quote_include_pipe != 1)
			free(curr->arr);
		if (curr->is_file && curr->is_quote_include_pipe != 1)
			free(curr->arr);
		if (curr == node_inf->tail)
			break ;
		curr = curr->next;
	}
}

int	syntax_error(t_node_inf *node_inf, int check)
{
	if (check == 0)
		return (0);
	else if (check == 1)
		printf("%s", "bash: syntax error near unexpected token `newline'\n");
	else if (check == 2)
		printf("%s", "bash: syntax error near unexpected token `|'\n");
	ft_syntax_free(node_inf);
	return (1);
}

void	control_process(t_vars *vars)
{
	t_node_inf	*node_inf;
	char		*input;
	char		***cmd;

	while (1)
	{
		set_readline_signal();
		input = readline("minishell $ ");
		if (is_empty_line(input))
			continue ;
		restore_signal();
		node_inf = parsing(vars, input);
		if (syntax_error(node_inf, check_parse_error(node_inf)))
			continue ;
		cmd = node_to_command(node_inf);
		if (node_inf->head->arr[0] == 0 || node_inf->head->arr[0] == 0)
			print_cmd_nfound(1, node_inf->head->arr);
		else
			execute_command(get_path_env(vars), cmd, node_inf);
		ft_free_file(node_inf);
		ft_free_3d(cmd);
		ft_free(node_inf);
	}
}

int	main(void)
{
	t_vars	*vars;

	vars = init_var();
	control_process(vars);
	ft_free_vars(vars);
}
