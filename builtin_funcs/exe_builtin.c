/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:50:41 by segan             #+#    #+#             */
/*   Updated: 2023/01/26 13:29:48 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exe_builtin(t_node_inf *node_inf)
{
	char	*cmd;

	cmd = node_inf->head->arr;
	if (is_equal(cmd, "echo"))
		builtin_echo(node_inf);
	else if (is_equal(cmd, "cd"))
		builtin_cd(node_inf);
	else if (is_equal(cmd, "pwd"))
		builtin_pwd();
	else if (is_equal(cmd, "export"))
		builtin_export(node_inf);
	else if (is_equal(cmd, "unset"))
		builtin_unset(node_inf);
	else if (is_equal(cmd, "env"))
		builtin_env(node_inf->vars->env);
	else if (is_equal(cmd, "exit"))
		builtin_exit(node_inf);
}
