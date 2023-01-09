/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 02:18:59 by segan             #+#    #+#             */
/*   Updated: 2023/01/09 17:30:10 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_cd(t_node_inf *node_inf)
{
	int	cd_ret;

	cd_ret = chdir(node_inf->head->next->arr);
	if (cd_ret == -1)
		perror(strerror(errno));
}
