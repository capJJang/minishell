/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 02:18:59 by segan             #+#    #+#             */
/*   Updated: 2022/12/24 02:28:18 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_cd(char **command)
{
	int	cd_ret;

	cd_ret = chdir(command[1]);
	if (cd_ret == -1)
	{
		perror(strerror(errno));
		exit(1);
	}
	exit(0);
}