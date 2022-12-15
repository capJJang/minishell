/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    check_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:12:57 by seyang            #+#    #+#             */
/*   Updated: 2022/12/12 19:12:58 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_child(char *path, char **command)
{
	if (execve(path, command, NULL) == -1)
	{
		exit(-1);
	}
}

int	is_parent(pid_t pid, char *path, char *command)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) == IS_COMMAND)
		return (IS_COMMAND);
	if (path == NULL)
	{
		printf("bash: %s: command not found\n", command);
		return (IS_NOT_FOUND);
	}
	return (IS_NOT_COMMAND);
}