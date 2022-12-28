/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 03:21:51 by segan             #+#    #+#             */
/*   Updated: 2022/12/27 03:30:53 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pwd(void)
{
	char	*getcwd_ret;

	getcwd_ret = NULL;
	getcwd_ret = getcwd(NULL, 0);
	if (!getcwd_ret)
		perror(strerror(errno));
	else
	{
		printf("%s\n", getcwd_ret);
		free(getcwd_ret);
	}
}
