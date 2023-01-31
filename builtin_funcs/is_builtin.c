/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:08:40 by segan             #+#    #+#             */
/*   Updated: 2023/01/30 19:10:45 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char **cmd)
{
	if (!ft_strncmp(cmd[0], "echo", 5))
		return (1);
	if (!ft_strncmp(cmd[0], "cd", 3))
		return (1);
	if (!ft_strncmp(cmd[0], "pwd", 4))
		return (1);
	if (!ft_strncmp(cmd[0], "export", 7))
		return (1);
	if (!ft_strncmp(cmd[0], "unset", 6))
		return (1);
	if (!ft_strncmp(cmd[0], "env", 4))
		return (1);
	if (!ft_strncmp(cmd[0], "exit", 5))
		return (1);
	return (0);
}
