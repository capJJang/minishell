/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 03:21:51 by segan             #+#    #+#             */
/*   Updated: 2023/02/01 18:38:49 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pwd(int	*stat)
{
	char	*pwd;

	pwd = ft_getcwd(stat);
	printf("%s\n", pwd);
	free(pwd);
	*stat = 0;
}
//exit status
