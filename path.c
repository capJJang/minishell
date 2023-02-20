/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:09:05 by seyang            #+#    #+#             */
/*   Updated: 2023/02/20 12:15:27 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path_env(t_vars *vars)
{
	char	**path_env;

	path_env = ft_split(ft_getenv(vars, "PATH"), ':');
	if (errno == ENOMEM)
		exit(-1);
	return (path_env);
}

char	*get_path(char **path_env, char *cmd)
{
	char	*path;
	int		i;

	if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
	i = 0;
	while (path_env[i])
	{
		path = ft_strjoin2(ft_strjoin(path_env[i], "/"), cmd, 1, 0);
		if (!path)
			exit(-1);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
		free(path);
	}
	return (IS_NOT_FOUND);
}
