/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:40:54 by segan             #+#    #+#             */
/*   Updated: 2023/02/16 16:47:55 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_vars	*init_var(void)
{
	t_vars	*vars;

	vars = ft_malloc(sizeof(t_vars));
	vars->env = init_env();
	vars->sh_var = NULL;
	vars->stat = ft_calloc(1, sizeof(int));
	return (vars);
}
