/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:50:41 by segan             #+#    #+#             */
/*   Updated: 2023/01/30 19:10:40 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exe_builtin(t_node_inf *node_inf)
{
	char	*cmd;

	cmd = node_inf->head->arr;
	if (!ft_strncmp(cmd, "echo", 5))
		builtin_echo(node_inf);
	else if (!ft_strncmp(cmd, "cd", 3))
		builtin_cd(node_inf);
	else if (!ft_strncmp(cmd, "pwd", 4))
		builtin_pwd();
	else if (!ft_strncmp(cmd, "export", 7))
		builtin_export(node_inf);
	else if (!ft_strncmp(cmd, "unset", 6))
		builtin_unset(node_inf);
	else if (!ft_strncmp(cmd, "env", 4))
		builtin_env(node_inf->vars->env);
	else if (!ft_strncmp(cmd, "exit", 5))
		builtin_exit(node_inf);
}
