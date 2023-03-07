/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overwrite_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:36:57 by segan             #+#    #+#             */
/*   Updated: 2023/03/06 20:55:47 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update__(t_child child)
{
	int		end;
	char	*temp_key;

	if (child.cmd[0][0] == 0)
		return ;
	end = 0;
	while (child.cmd[0][end])
		end++;
	if (!ft_node_strncmp(child.node_inf, "env"))
		ft_overwrite_env(child.node_inf->vars, "_", "env");
	else if (!ft_node_strncmp(child.node_inf, "|"))
		ft_overwrite_env(child.node_inf->vars, "_", "");
	else if (!ft_strncmp(child.cmd[0][0], "export", 7))
	{
		temp_key = ft_getkey(child.cmd[0][end - 1]);
		ft_overwrite_env(child.node_inf->vars, "_", temp_key);
		free(temp_key);
	}
	else
		ft_overwrite_env(child.node_inf->vars, "_", child.cmd[0][end - 1]);
}

void	ft_overwrite_env(t_vars *vars, char *key, char *val)
{
	int		i;
	char	*temp_key;

	i = 0;
	while (vars->env[i])
	{
		temp_key = ft_getkey(vars->env[i]);
		if (!ft_strncmp(temp_key, key, ft_strlen(key) + 1))
		{
			free(vars->env[i]);
			vars->env[i] = ft_strjoin2(ft_strjoin(key, "="), val, 1, 0);
			free(temp_key);
			return ;
		}
		free(temp_key);
		i++;
	}
	ft_addenv(vars, key, ft_strjoin("=", val));
}
