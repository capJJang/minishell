/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:00:34 by segan             #+#    #+#             */
/*   Updated: 2023/03/08 17:26:07 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_append_env(t_vars *vars, char *key, char *val)
{
	int		i;

	i = -1;
	while (vars->env[++i])
	{
		if (ft_strncmp(vars->env[i], key, ft_strlen(key)))
			continue ;
		if (ft_strchr(vars->env[i], '=') == ft_strrchr(vars->env[i], '='))
			val++;
		vars->env[i] = ft_strjoin2(vars->env[i], val, 1, 0);
		return ;
	}
	ft_addenv(vars, key, ft_strdup(val));
	ft_unset_sh_var(vars, key);
}
