/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:50:41 by segan             #+#    #+#             */
/*   Updated: 2023/01/25 19:08:01 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exe_builtin(t_node_inf *node_inf)
{
	char	*cmd;

	cmd = node_inf->head->arr;
	if (!ft_strncmp(cmd, "echo", ft_strlen(cmd)))
		builtin_echo(node_inf);
	if (!ft_strncmp(cmd, "cd", ft_strlen(cmd)))
		builtin_cd(node_inf);
	if (!ft_strncmp(cmd, "pwd", ft_strlen(cmd)))
		builtin_pwd();
	if (!ft_strncmp(cmd, "export", ft_strlen(cmd)))
		builtin_export(node_inf);
	// if (!ft_strncmp(cmd, "unset", ft_strlen(cmd)))
	// 	builtin_unset(node_inf);
	if (!ft_strncmp(cmd, "env", ft_strlen(cmd)))
		builtin_env(node_inf->vars->env);
	if (!ft_strncmp(cmd, "exit", ft_strlen(cmd)))
		builtin_exit(node_inf);
}
