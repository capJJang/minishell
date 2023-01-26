/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:43:59 by segan             #+#    #+#             */
/*   Updated: 2023/01/26 09:50:33 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unsetenv(t_vars *vars, char *key)
{
	char	**old_env;
	int		i;

	i = 0;
	while (vars->env[i])
	{
		if (!ft_strncmp(vars->env[i], key, ft_strlen(key)))
		{
			free(vars->sh_var[i]);
			break ;
		}
		i++;
	}
	while (vars->env[i] && i > 1)
	{
		vars->sh_var[i - 1] = vars->sh_var[i];
		i++;
	}
	vars->sh_var[i] = 0;
	old_env = vars->sh_var;
	vars->sh_var = ft_strdup_2d(old_env);
	ft_free_2d(old_env);
}

void	ft_unset_sh_var(t_vars *vars, char *key)
{
	char	**old_sh_var;
	int		i;

	i = 0;
	while (vars->sh_var[i])
	{
		if (!ft_strncmp(vars->sh_var[i], key, ft_strlen(key)))
		{
			free(vars->sh_var[i]);
			break ;
		}
		i++;
	}
	while (vars->sh_var[i] && i > 1)
	{
		vars->sh_var[i - 1] = vars->sh_var[i];
		i++;
	}
	vars->sh_var[i] = 0;
	old_sh_var = vars->sh_var;
	vars->sh_var = ft_strdup_2d(old_sh_var);
	ft_free_2d(old_sh_var);
}
