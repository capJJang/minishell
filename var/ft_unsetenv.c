/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:43:59 by segan             #+#    #+#             */
/*   Updated: 2023/01/27 19:03:06 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unsetenv(t_vars *vars, char *key)
{
	char	**old_env;
	char	*temp_key;
	int		i;

	if (!vars->env)
		return ;
	i = 0;
	while (vars->env[i])
	{
		temp_key = ft_getkey(vars->env[i]);
		if (is_equal(temp_key, key))
			break ;
		free(temp_key);
		i++;
	}
	free(temp_key);
	free(vars->env[i]);
	vars->env[i] = NULL;
	while (vars->env[i] && i > 1)
	{
		vars->env[i] = vars->env[i + 1];
		i++;
	}
	old_env = vars->env;
	vars->env = ft_strdup_2d(old_env);
	ft_free_2d(old_env);
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
		if (is_equal(vars->sh_var[i], key))
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
