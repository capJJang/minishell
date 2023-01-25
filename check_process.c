/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:12:57 by seyang            #+#    #+#             */
/*   Updated: 2023/01/25 19:23:33 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_child_1(char *path, char **cmd)
{
	if (execve(path, cmd, NULL) == -1)
	{
		exit(-1);
	}
}

int	is_parent_1(pid_t pid, char *path, char *cmd)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) == IS_COMMAND)
		return (IS_COMMAND);
	if (path == NULL)
	{
		printf("bash: %s: cmd not found\n", cmd);
		return (IS_NOT_FOUND);
	}
	return (IS_NOT_COMMAND);
}
