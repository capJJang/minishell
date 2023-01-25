/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:09:05 by seyang            #+#    #+#             */
/*   Updated: 2023/01/25 19:23:33 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path_env(char **env)
{
	char	**path_env;

	path_env = ft_split(ft_getenv(env, "PATH"), ':');
	if (path_env == NULL)
		exit(-1);
	return (path_env);
}

char	*get_path(char **path_env, char *cmd)
{
	char	*path;
	char	*temp;
	int		i;

	if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
	i = 0;
	while (path_env[i])
	{
		temp = ft_strjoin(path_env[i], "/");
		if (temp == NULL)
			exit(-1);
		path = ft_strjoin(temp, cmd);
		if (path == NULL)
			exit(-1);
		free(temp);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
		free(path);
	}
	temp = getcwd(NULL, 0);
	if (temp == NULL)
		exit(-1);
	path = ft_strjoin(temp, "/");
	if (path == NULL)
		exit(-1);
	free(temp);
	temp = ft_strjoin(path, cmd);
	free(path);
	if (access(temp, X_OK) == 0)
		return (temp);
	free(temp);
	return (IS_NOT_FOUND);
}
