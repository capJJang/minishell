/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:24:08 by segan             #+#    #+#             */
/*   Updated: 2023/01/20 05:55:11 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//인자가 없으면 셸변수와, 환경변수를 정렬 - > 출력
//인자가 있는데 값이 없으면 셸변수로 등록 -> 셸 변수가 없
//인자가 있고 값이 있는 경우 -> 존재하지 않으면 새로 등록
//					   -> 이미 존재하는 변수면 값 갱신

// void	add_sh_var(t_node_inf *node_inf, char *val)
// {
// 	char	**sh_env;

// 	if (!node_inf->sh_var)
// 		sh_env = (char **)ft_malloc(sizeof(char *) * 2);
// }

// void	builtin_export(t_node_inf *node_inf)
// {
// 	t_node	*arg;

// 	arg = node_inf->head->next;
// 	if (node_inf->head == node_inf->tail)	//print export
// 		;//sort_vars(); print_vars();
// 	else if (!ft_strchr(arg->arr, '='))	//export shell env
// 		add_sh_var(node_inf->env, node_inf->head->arr);
// 	else if (ft_strnstr(arg->arr, "+=", ft_srtlen(arg->arr))) //append to exist var
// 	;
// 	else if (ft_strchr(arg->arr, '='))	//export new env or replace env value
// 	;
// }
