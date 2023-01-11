/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:08:57 by segan             #+#    #+#             */
/*   Updated: 2023/01/11 18:58:47 by segan            ###   ########.fr       */
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

void	ft_strcpy_2d(char **dst, char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	dst[i] = 0;
}

char	**init_env(void)
{
	extern char	**environ;
	char		**ret;
	int			len;
	int			i;

	len = ft_strlen_2d(environ);
	i = 0;
	ret = (char **)ft_malloc(sizeof(char *) * (len + 1));
	ft_strcpy_2d(ret, environ);
	return (ret);
}
