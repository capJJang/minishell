/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:40:54 by segan             #+#    #+#             */
/*   Updated: 2023/01/31 16:03:48 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_vars	*init_var(void)
{
	t_vars	*vars;

	vars = ft_malloc(sizeof(t_vars));
	vars->env = init_env();
	vars->sh_var = NULL;
	vars->stat = ft_malloc(sizeof(int));
	return (vars);
}
