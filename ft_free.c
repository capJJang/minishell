/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:52:24 by seyang            #+#    #+#             */
/*   Updated: 2023/03/08 18:52:08 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_runtime(pid_t *pid, int **fd, char **path_env)
{
	free(pid);
	ft_free_2d((char **)fd);
	ft_free_2d(path_env);
}

void	ft_free_vars(t_vars *vars)
{
	ft_free_2d(vars->env);
	ft_free_2d(vars->sh_var);
	free(vars);
	exit (0);
}

void	ft_free_2d(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_free_3d(char ***arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		ft_free_2d(arr[i++]);
	free(arr);
}

void	ft_free(t_node_inf *node_inf)
{
	t_node	*curr;
	t_node	*next;

	curr = node_inf->head;
	node_inf->tail->next = 0;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(node_inf);
}
