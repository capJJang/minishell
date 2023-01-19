/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:08:57 by segan             #+#    #+#             */
/*   Updated: 2023/01/12 18:16:27 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_environ(char **environ)
{
	int	i;

	i = 0;
	while (environ[i])
		printf("%s\n", environ[i++]);
}

int	ft_strlen_2d(char **arr)
{
	int	i;

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
