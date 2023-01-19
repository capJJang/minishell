/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:11:53 by segan             #+#    #+#             */
/*   Updated: 2023/01/13 17:55:09 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_addenv(t_vars *var, char *val)
{
	char	**new_env;
	int		len;

	len = ft_strlen_2d(var->env) + 1;
	new_env = (char **)ft_malloc(sizeof(char *) * (len + 1));
	new_env = ft_strdup_2d(var->env);
	new_env[len - 1] = ft_strdup(val);
	new_env[len] = 0;
	ft_free_2d(var->env);
	var->env = new_env;
}
