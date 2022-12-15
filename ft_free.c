/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:13:13 by seyang            #+#    #+#             */
/*   Updated: 2022/12/13 19:13:14 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node_inf  *free_node_inf(t_node_inf *node_inf)
{
    free(node_inf->head);
    free(node_inf->tail);
    free(node_inf);
    return (0);
}