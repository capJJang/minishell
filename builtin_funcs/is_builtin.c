/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:08:40 by segan             #+#    #+#             */
/*   Updated: 2023/01/25 19:23:33 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char **cmd)
{
	if (!ft_strncmp(cmd[0], "echo", ft_strlen(cmd[0])))
		return (1);
	if (!ft_strncmp(cmd[0], "cd", ft_strlen(cmd[0])))
		return (1);
	if (!ft_strncmp(cmd[0], "pwd", ft_strlen(cmd[0])))
		return (1);
	if (!ft_strncmp(cmd[0], "export", ft_strlen(cmd[0])))
		return (1);
	if (!ft_strncmp(cmd[0], "unset", ft_strlen(cmd[0])))
		return (1);
	if (!ft_strncmp(cmd[0], "env", ft_strlen(cmd[0])))
		return (1);
	if (!ft_strncmp(cmd[0], "exit", ft_strlen(cmd[0])))
		return (1);
	return (0);
}
