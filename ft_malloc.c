/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:03:35 by seyang            #+#    #+#             */
/*   Updated: 2022/12/13 21:04:18 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    *ft_malloc(size_t size)
{
	void    *ptr;

    ptr = malloc(size);
    if (ptr == NULL)
        exit(-1);
    return (ptr);
}
