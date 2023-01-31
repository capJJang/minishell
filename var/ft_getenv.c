/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:54:00 by segan             #+#    #+#             */
/*   Updated: 2023/01/30 17:33:25 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	ft_get_keyidx(t_vars *vars)

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

char	*ft_getenv(char **env, const char *str)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], str, ft_strlen(str)))
			return ((ft_strchr(env[i], '=') + 1));
		i++;
	}
	return (NULL);
}
