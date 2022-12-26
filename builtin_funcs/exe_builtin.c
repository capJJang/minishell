/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:50:41 by segan             #+#    #+#             */
/*   Updated: 2022/12/27 01:25:32 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exe_builtin(t_node_inf *node_inf)
{
	if (!ft_strncmp(node_inf->head->arr, "echo", ft_strlen(node_inf->head->arr)))
	 	builtin_echo(node_inf);
	if (!ft_strncmp(node_inf->head->arr, "cd", ft_strlen(node_inf->head->arr)))
		builtin_cd(node_inf);
	// if (!ft_strncmp(node_inf->head->arr, "pwd", ft_strlen(node_inf->head->arr)))
	// 	builtin_pwd();
	// if (!ft_strncmp(node_inf->head->arr, "export", ft_strlen(node_inf->head->arr)))
	// 	builin_export(node_inf);
	// if (!ft_strncmp(node_inf->head->arr, "unset", ft_strlen(node_inf->head->arr)))
	// 	builtin_unset(node_inf);
	// if (!ft_strncmp(node_inf->head->arr, "env", ft_strlen(node_inf->head->arr)))
	// 	builtin_env();
	if (!ft_strncmp(node_inf->head->arr, "exit", ft_strlen(node_inf->head->arr)))
		builtin_exit(node_inf);
}
