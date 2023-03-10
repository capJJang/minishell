/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 02:18:59 by segan             #+#    #+#             */
/*   Updated: 2023/03/08 18:57:58 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_wd(t_vars *vars, char *pwd, char *oldpwd)
{
	ft_overwrite_env(vars, "PWD", pwd);
	ft_overwrite_env(vars, "OLDPWD", oldpwd);
	free(oldpwd);
	free(pwd);
}

void	builtin_cd(t_node_inf *node_inf)
{
	int		cd_ret;
	char	*oldpwd;
	char	*pwd;

	oldpwd = ft_getcwd(node_inf->vars->stat);
	if (node_inf->cmd[1] == NULL)
		pwd = ft_getenv(node_inf->vars, "HOME");
	else
		pwd = node_inf->cmd[1];
	if (!pwd)
	{
		printf("bash: cd: HOME not set\n");
		*node_inf->vars->stat = 1;
		return ;
	}
	cd_ret = chdir(pwd);
	if (cd_ret == -1)
	{
		perror(strerror(errno));
		*node_inf->vars->stat = 1;
	}
	pwd = ft_getcwd(node_inf->vars->stat);
	update_wd(node_inf->vars, pwd, oldpwd);
	*node_inf->vars->stat = 0;
}
