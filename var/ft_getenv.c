/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:54:00 by segan             #+#    #+#             */
/*   Updated: 2023/02/16 19:44:41 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getkey(char *var)
{
	char	*key;
	int		len;

	len = 0;
	while (var[len] != '+' && var[len] != '=' && var[len])
		len++;
	if (len <= 0)
		return (ft_strdup(var));
	key = ft_malloc(sizeof(char) * (len + 1));
	ft_strlcpy(key, var, len + 1);
	return (key);
}

char	*ft_getenv(t_vars *vars, const char *str)
{
	int		i;
	int		ncmp_ret;
	char	*key;

	i = 0;
	while (vars->env[i])
	{
		key = ft_strjoin(str, "=");
		ncmp_ret = 0;
		ncmp_ret = ft_strncmp(vars->env[i], key, ft_strlen(key));
		free(key);
		if (!ncmp_ret)
			return ((ft_strchr(vars->env[i], '=') + 1));

		i++;
	}
	if (!ft_strncmp(str, "?", 2))
		return (ft_itoa(*vars->stat));
	return (NULL);
}
