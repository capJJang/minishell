/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_single_or_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:57:37 by seyang            #+#    #+#             */
/*   Updated: 2022/12/13 21:57:38 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    set_single_or_double(char *arr, int start)
{
    int i_single_1;
    int i_single_2;
    int i_double_1;
    int i_double_2;

    i_single_1 = ft_find_after_chr(arr, start, '\'');
    i_double_1 = ft_find_after_chr(arr, start, '\"');
    if (arr[i_single_1] != 0)
        i_single_2 = ft_find_after_chr(arr, i_single_1 + 1, '\'');
    if (arr[i_double_1] != 0)
        i_double_2 = ft_find_after_chr(arr, i_double_1 + 1, '\"');
    if ((arr[i_single_1] == 0 || arr[i_single_2] == 0) \
        && (arr[i_double_1] == 0 || arr[i_double_2] == 0))
            return (0);
    else if (arr[i_single_1] == 0 || arr[i_single_2] == 0)
        return ('\"');
    else if (arr[i_double_2] == 0 || arr[i_double_2] == 0)
        return ('\'');
    if (i_single_1 > i_double_1)
        return ('\"');
    else
        return ('\'');
}