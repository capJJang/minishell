/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:09:05 by seyang            #+#    #+#             */
/*   Updated: 2022/12/12 19:09:07 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path_env(void)
{
	char	**path_env;
	
	path_env = ft_split(getenv("PATH"), ':');
	if (path_env == NULL)
		exit(-1);
	return (path_env);
}

char	*get_path(char *path_env, char *command)
{
	char	*path;
	char	*temp;

	temp = ft_strjoin(path_env, "/");
	if (temp == NULL)
		exit(-1);
	path = ft_strjoin(temp, command);
	if (path == NULL)
		exit(-1);
	free(temp);
	return (path);
}