/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:09:05 by seyang            #+#    #+#             */
/*   Updated: 2023/03/08 18:55:53 by seyang           ###   ########.fr       */
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

char	*get_path(char **path_env, char *cmd, int *stat)
{
	char	*path;
	int		i;

	*stat = 0;
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (!path_env)
	{
		*stat = 2;
		return (NULL);
	}
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
	*stat = 1;
	return (IS_NOT_FOUND);
}
