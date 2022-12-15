/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:44:07 by seyang            #+#    #+#             */
/*   Updated: 2022/12/13 19:44:08 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    print_node(t_node_inf *node_inf)
{
    t_node  *curr;

    curr = node_inf->head;
    while (1)
    {
        printf("%s\n", curr->arr);
        if (curr == node_inf->tail)
            break ;
        curr = curr->next;
    }
}