/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:08:40 by segan             #+#    #+#             */
/*   Updated: 2023/01/26 13:08:04 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char **cmd)
{
	if (is_equal(cmd[0], "echo"))
		return (1);
	if (is_equal(cmd[0], "cd"))
		return (1);
	if (is_equal(cmd[0], "pwd"))
		return (1);
	if (is_equal(cmd[0], "export"))
		return (1);
	if (is_equal(cmd[0], "unset"))
		return (1);
	if (is_equal(cmd[0], "env"))
		return (1);
	if (is_equal(cmd[0], "exit"))
		return (1);
	return (0);
}
