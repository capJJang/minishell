/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:43:59 by segan             #+#    #+#             */
/*   Updated: 2023/01/24 14:32:22 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	ft_unsetenv(t_node_inf *node_inf, char *val)
// {
	
// }

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
			break;
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
