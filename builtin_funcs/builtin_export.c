/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:24:08 by segan             #+#    #+#             */
/*   Updated: 2023/01/24 14:41:45 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_export(t_node_inf *node_inf)
{
	t_node	*arg;
	char	*key;
	char	*val;
	
	arg = node_inf->head->next;
	if (node_inf->head == node_inf->tail)	//print export
		print_sh_var(node_inf->vars);
	while (arg != node_inf->head)
	{
		key = ft_getkey(arg->arr);
		val = ft_strchr(arg->arr, '=');
		if (!val)												//셸 변수 등록 하는 경우
			ft_add_sh_var(node_inf->vars, arg->arr);
		else if (ft_strnstr(arg->arr, "+=", ft_strlen(arg->arr)))	//append 하는 경우
			ft_append_env(node_inf->vars, key, val);
		else													//새로 등록
			ft_addenv(node_inf->vars, key, val);
		arg = arg->next;
		free(key);
	}
}
