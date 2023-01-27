/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 02:18:59 by segan             #+#    #+#             */
/*   Updated: 2023/01/27 14:34:53 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_cd(t_node_inf *node_inf)
{
	int		cd_ret;
	char	*oldpwd;
	char	*pwd;

	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		perror(strerror(errno));
	if (node_inf->cmd[1] == NULL || !ft_strncmp(node_inf->cmd[1], "~", 2))
		pwd = ft_getenv(node_inf->vars->env, "HOME");
	else
		pwd = node_inf->cmd[1];
	if (!pwd)
		perror(strerror(errno));
	cd_ret = chdir(pwd);
	if (cd_ret == -1)
		perror(strerror(errno));
	pwd = getcwd(NULL, 0);
	if (!pwd)
		perror(strerror(errno));
	else
	{
		ft_overwrite_env(node_inf->vars, "PWD", pwd);
		ft_overwrite_env(node_inf->vars, "OLDPWD", oldpwd);
	}
	free(oldpwd);
	free(pwd);
}
//exit status
//~ 과 인자가 없는건 다르게 동작함...