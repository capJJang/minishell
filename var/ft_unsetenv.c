/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:43:59 by segan             #+#    #+#             */
/*   Updated: 2023/03/06 19:49:57 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unsetenv2(t_vars *vars, int i)
{
	char	**old_env;

	while (vars->env[i])
	{
		vars->env[i] = vars->env[i + 1];
		i++;
	}
	*vars->stat = 0;
	if (i != ft_strlen_2d(vars->env))
	{
		old_env = vars->env;
		vars->env = ft_strdup_2d(old_env);
		ft_free_2d(old_env);
	}
}

void	ft_unsetenv(t_vars *vars, char *key)
{
	char	*temp_key;
	int		i;
	int		strncmp_ret;

	if (!vars->env)
		return ;
	i = 0;
	while (vars->env[i])
	{
		temp_key = ft_getkey(vars->env[i]);
		strncmp_ret = ft_strncmp(temp_key, key, ft_strlen(key) + 1);
		free(temp_key);
		temp_key = NULL;
		if (strncmp_ret == 0)
		{
			free(vars->env[i]);
			break ;
		}
		i++;
	}
	ft_unsetenv2(vars, i);
}

void	ft_unset_sh_var(t_vars *vars, char *key)
{
	char	**old_sh_var;
	int		i;

	if (!vars->sh_var)
		return ;
	i = 0;
	while (vars->sh_var[i])
	{
		if (!ft_strncmp(vars->sh_var[i], key, ft_strlen(key) + 1))
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
	old_sh_var = vars->sh_var;
	vars->sh_var = ft_strdup_2d(old_sh_var);
	ft_free_2d(old_sh_var);
}
