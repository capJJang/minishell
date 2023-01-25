/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:05:57 by segan             #+#    #+#             */
/*   Updated: 2023/01/25 19:23:33 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	control_process(t_vars *vars)
{
	t_node_inf	*node_inf;
	char		***cmd;

	while (1)
	{
		node_inf = parsing(readline("minishell $ "));
		if (node_inf == EMPTY_LINE)
			continue ;
		// print_node(node_inf);	// print_test
		cmd = node_to_command(node_inf);
		// print_command(cmd);	// print_test
		node_inf->vars = vars;
		execute_command(get_path_env(vars->env), cmd, node_inf);
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
