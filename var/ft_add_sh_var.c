/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sh_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:56:59 by segan             #+#    #+#             */
/*   Updated: 2023/01/23 13:01:28 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_add_sh_var(t_vars *var, char *val)
{
	char	**new_sh_var;
	int		len;
	int		i;

	len = ft_strlen_2d(var->sh_var) + 1;
	i = 0;
	new_sh_var = (char **)ft_malloc(sizeof(char *) * (len + 1));
	while (i < len - 1)
	{
		new_sh_var[i] = ft_strdup(var->sh_var[i]);
		i++;
	}
	new_sh_var[len - 1] = ft_strdup(val);
	new_sh_var[len] = 0;
	ft_free_2d(var->sh_var);
	var->sh_var = new_sh_var;
}
