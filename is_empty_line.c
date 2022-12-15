/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:41:22 by seyang            #+#    #+#             */
/*   Updated: 2022/12/13 20:41:32 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_empty_line(char *read_line)
{
    if (read_line[0] == 0)
    {
        free(read_line);
        return (1);
    }
    return (0);
}