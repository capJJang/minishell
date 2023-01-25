/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:08:01 by seyang            #+#    #+#             */
/*   Updated: 2023/01/25 19:23:33 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cmd_nfound(int error, char *cmd)
{
	if (error == IS_NOT_FOUND)
		printf("bash: %s: cmd not found\n", cmd);
}

void	print_errno_in_child(char *cmd)
{
	if (errno == PERMISSION_DENIED)
		printf("bash: %s: Permission denied\n", cmd);
	else
		perror(strerror(errno));
	exit (errno);
}
