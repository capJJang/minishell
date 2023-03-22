/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:08:01 by seyang            #+#    #+#             */
/*   Updated: 2023/03/19 17:02:11 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cmd_nfound(int error, char *cmd)
{
	if (error == 1)
		printf("bash: %s: command not found\n", cmd);
	else if (error == 2)
		printf("bash: %s: No such file or directory\n", cmd);
}

void	print_errno_in_child(char *cmd)
{
	if (errno == PERMISSION_DENIED)
		printf("bash: %s: Permission denied\n", cmd);
	else
		perror(strerror(errno));
	exit (errno);
}

void	print_invalid_id(t_node_inf *node_inf, char *key, char *arg)
{
	printf("bash: %s: `%s': not a valid identifier\n", node_inf->cmd[0], arg);
	*(node_inf->vars->stat) = 1;
	free(key);
}
