/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:24:08 by segan             #+#    #+#             */
/*   Updated: 2023/01/26 11:28:55 by segan            ###   ########.fr       */
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
	while (i < len - 1)
	{
		if (!ft_isalnum(key[i]) || key[i] == '_')
			check = 0;
		i++;
	}
	if (!ft_isalnum(key[i]) || key[i] == '_' || key[i] == '+')
		check = 0;
	return (check);
}

void	builtin_export(t_node_inf *node_inf)
{
	int		i;
	char	*key;
	char	*val;

	i = 1;
	if (node_inf->head == node_inf->tail)//print export
		print_sh_var(node_inf->vars);
	while (node_inf->cmd[i])
	{
		key = ft_getkey(node_inf->cmd[i]);
		if (!check_valid_key(key))
		{
			printf("bash: export:`%s': not a valid identifier\n", node_inf->cmd[i]);
			free(key);
			break ;
		}
		val = ft_strchr(node_inf->cmd[i], '=');
		if (!val)//셸 변수 등록 하는 경우
			ft_add_sh_var(node_inf->vars, node_inf->cmd[i]);
		else if (ft_strnstr(node_inf->cmd[i], "+=", ft_strlen(node_inf->cmd[i]))) //append 하는 경우
			ft_append_env(node_inf->vars, key, val);
		else//새로 등록
			ft_addenv(node_inf->vars, key, val);
		i++;
		free(key);
	}
}
//exit status