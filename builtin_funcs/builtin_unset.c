/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:53:02 by segan             #+#    #+#             */
/*   Updated: 2023/02/16 16:58:17 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_unset(t_node_inf *node_inf)
{
	int		i;
	char	*key;
	char	*val;

	i = 1;
	while (node_inf->cmd[i])
	{
		key = ft_getkey(node_inf->cmd[i]);
		val = ft_getenv(node_inf->vars, key);
		if (!check_valid_key(key))
			return (print_invalid_id(node_inf, key, node_inf->cmd[i]));
		if (!val)
			ft_unset_sh_var(node_inf->vars, key);
		else
			ft_unsetenv(node_inf->vars, key);
		free(key);
		i++;
	}
	*node_inf->vars->stat = 0;
}
