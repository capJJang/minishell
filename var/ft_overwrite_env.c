/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overwrite_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:36:57 by segan             #+#    #+#             */
/*   Updated: 2023/01/31 17:35:01 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
