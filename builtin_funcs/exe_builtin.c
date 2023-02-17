/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:50:41 by segan             #+#    #+#             */
/*   Updated: 2023/02/17 18:06:21 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int	is_redirection2(t_node_inf *node_inf)
{
	if (!ft_node_strncmp(node_inf, ">"))
		return (1);
	if (!ft_node_strncmp(node_inf, ">>"))
		return (1);
	if (!ft_node_strncmp(node_inf, "<"))
		return (1);
	if (!ft_node_strncmp(node_inf, "<<"))
		return (1);
	return (0);
}

void	exe_builtin(t_node_inf *node_inf)
{
	char	*cmd;

	//ft_overwrite_env(node_inf->vars, "_", node_inf->cmd[ft_strlen_2d(node_inf->cmd) - 1]); 파이프가 없을 때만 실행 되어야함ㄴ
	cmd = node_inf->cmd[0];
	if (!ft_strncmp(cmd, "echo", 5))
		builtin_echo(node_inf);
	else if (!ft_strncmp(cmd, "cd", 3))
		builtin_cd(node_inf);
	else if (!ft_strncmp(cmd, "pwd", 4))
		builtin_pwd(node_inf->vars->stat);
	else if (!ft_strncmp(cmd, "export", 7))
		builtin_export(node_inf);
	else if (!ft_strncmp(cmd, "unset", 6))
		builtin_unset(node_inf);
	else if (!ft_strncmp(cmd, "env", 4))
		builtin_env(node_inf->vars);
	else if (!ft_strncmp(cmd, "exit", 5))
		builtin_exit(node_inf);
	if (!ft_node_strncmp(node_inf, "|") || is_redirection2(node_inf))
		exit(*node_inf->vars->stat);
}

