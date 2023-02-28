/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:24:08 by segan             #+#    #+#             */
/*   Updated: 2023/02/28 16:57:53 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_valid_key(char *key)
{
	int	i;
	int	len;
	int	check;

	check = 1;
	i = 0;
	len = ft_strlen(key);
	if (!ft_isalpha(*key) && *key != '_')
		return (0);
	while (i < len - 1)
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			check = 0;
		i++;
	}
	if (!ft_isalnum(key[i]) && key[i] != '_' && key[i] != '+')
		check = 0;
	return (check);
}

void	builtin_export(t_node_inf *node_inf)
{
	int		i;
	char	*key;
	char	*val;

	i = 1;
	if (node_inf->head == node_inf->tail)
		print_sh_var(node_inf->vars);
	while (node_inf->cmd[i])
	{
		key = ft_getkey(node_inf->cmd[i]);
		if (!check_valid_key(key))
			return (print_invalid_id(node_inf, key, node_inf->cmd[i]));
		val = ft_strchr(node_inf->cmd[i], '=');
		if (!val)
			ft_add_sh_var(node_inf->vars, node_inf->cmd[i]);
		else if (ft_strnstr(node_inf->cmd[i], "+=", \
		ft_strlen(node_inf->cmd[i])))
			ft_append_env(node_inf->vars, key, val);
		else
			ft_overwrite_env(node_inf->vars, key, val + 1);
		i++;
		free(key);
	}
	*node_inf->vars->stat = 0;
}
//exit status
