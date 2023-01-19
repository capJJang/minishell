/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:40:54 by segan             #+#    #+#             */
/*   Updated: 2023/01/20 05:57:43 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_vars	*init_var(void)
{
	t_vars	*var;

	var = ft_malloc(sizeof(t_vars));
	var->env = init_env();
	var->sh_var = NULL;
	return (var);
}