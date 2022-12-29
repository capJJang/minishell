/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:08:01 by seyang            #+#    #+#             */
/*   Updated: 2022/12/24 03:13:08 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cmd_nfound(int error, char *command)
{
	if (error == IS_NOT_FOUND)
		printf("bash: %s: command not found\n", command);
	// exit (127);
}

void	print_errno_in_child(char *command)
{
	// printf("%d\n", errno);
	if (errno == PERMISSION_DENIED)
		printf("bash: %s: Permission denied\n", command);
	else
		perror(strerror(errno));
	exit (errno);
}