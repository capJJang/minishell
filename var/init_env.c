/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:08:57 by segan             #+#    #+#             */
/*   Updated: 2023/01/26 09:50:46 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_environ(char **environ)
{
	int	i;

	i = 0;
	if (!environ)
		return ;
	while (environ[i])
		printf("%s\n", environ[i++]);
}

void	print_sh_var(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->env[i])
		printf("declare -x %s\n", vars->env[i++]);
	if (!vars->sh_var)
		return ;
	i = 0;
	while (vars->sh_var[i])
		printf("declare -x %s\n", vars->sh_var[i++]);
}

int	ft_strlen_2d(char **arr)
{
	int	i;

	if (arr == NULL)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**ft_strdup_2d(char **src)
{
	char	**ret;
	int		len;
	int		i;

	len = ft_strlen_2d(src);
	ret = (char **)ft_malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (src[i])
	{
		ret[i] = ft_strdup(src[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	**init_env(void)
{
	extern char	**environ;
	char		**ret;

	ret = ft_strdup_2d(environ);
	return (ret);
}
