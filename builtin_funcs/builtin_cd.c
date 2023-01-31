/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 02:18:59 by segan             #+#    #+#             */
/*   Updated: 2023/01/31 17:37:20 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_argc(t_node_inf *node_inf)
{
	if (node_inf->cmd[2])
	{
		printf("bash: cd: %s:No such file of directory\n", node_inf->cmd[1]);
		*node_inf->vars->stat = 1;
		return (0);
	}
	return (1);
}

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

	if (!check_argc(node_inf))
		return ;
	oldpwd = getcwd(NULL, 0);
	if (errno == ENOMEM)
		exit(-1);
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
		update_wd(node_inf->vars, pwd, oldpwd);
}
//exit status
//~ 과 인자가 없는건 다르게 동작함...