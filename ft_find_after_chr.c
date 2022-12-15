/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_after_chr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:20:08 by seyang            #+#    #+#             */
/*   Updated: 2022/12/13 20:20:12 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_find_after_chr(char *arr, int start, char c)
{
    int i;

    i = start;
    if (arr == NULL)
        return (-1);
    while (*arr)
    {
        if (arr[i] == c || arr[i] == 0)
            return (i);
        i++;
    }
    return (-1);
}
