/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:05:57 by segan             #+#    #+#             */
/*   Updated: 2023/02/21 13:49:02 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (check_parse_error(node_inf) == 1)
		{
			printf("%s", "bash: syntax error near unexpected token `newline'\n");
			continue ;
		}
		cmd = node_to_command(node_inf);
		execute_command(get_path_env(vars), cmd, node_inf);
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
