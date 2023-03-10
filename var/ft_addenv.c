/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:11:53 by segan             #+#    #+#             */
/*   Updated: 2023/03/08 18:58:17 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_addenv(t_vars *var, char *key, char *val)
{
	char	**new_env;
	int		len;
	int		i;

	len = ft_strlen_2d(var->env) + 1;
	i = 0;
	new_env = (char **)ft_malloc(sizeof(char *) * (len + 1));
	while (i < len - 1)
	{
		new_env[i] = ft_strdup(var->env[i]);
		i++;
	}
	new_env[len - 1] = ft_strjoin(key, val);
	free(val);
	new_env[len] = 0;
	ft_free_2d(var->env);
	var->env = new_env;
}
