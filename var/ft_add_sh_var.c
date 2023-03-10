/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sh_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:56:59 by segan             #+#    #+#             */
/*   Updated: 2023/03/08 18:58:15 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	check_duplication_var(t_vars *var, char *val)
{
	int	i;

	i = 0;
	if (var->sh_var == NULL)
		return (false);
	while (var->sh_var[i])
	{
		if (ft_strncmp(val, var->sh_var[i], ft_strlen(val)) == 0)
			return (true);
		i++;
	}
	return (false);
}

void	ft_add_sh_var(t_vars *var, char *val)
{
	char	**new_sh_var;
	int		len;
	int		i;

	if (check_duplication_var(var, val) || ft_getenv(var, val))
		return ;
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
