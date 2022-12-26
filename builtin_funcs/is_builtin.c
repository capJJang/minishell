/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:08:40 by segan             #+#    #+#             */
/*   Updated: 2022/12/27 00:06:26 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char **command)
{
	if (!ft_strncmp(command[0], "echo", ft_strlen(command[0])))
		return (1);
	if (!ft_strncmp(command[0], "cd", ft_strlen(command[0])))
		return (1);
	if (!ft_strncmp(command[0], "pwd", ft_strlen(command[0])))
		return (1);
	if (!ft_strncmp(command[0], "export", ft_strlen(command[0])))
		return (1);
	if (!ft_strncmp(command[0], "unset", ft_strlen(command[0])))
		return (1);
	if (!ft_strncmp(command[0], "env", ft_strlen(command[0])))
		return (1);
	if (!ft_strncmp(command[0], "exit", ft_strlen(command[0])))
		return (1);
	return (0);
}
