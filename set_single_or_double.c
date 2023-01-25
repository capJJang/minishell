/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_single_or_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:51:26 by seyang            #+#    #+#             */
/*   Updated: 2022/12/16 18:02:58 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	set_single_or_double(char *arr, int start)
{
	int	sqoute_start;
	int	sqoute_end;
	int	dqoute_start;
	int	dqoute_end;

	if (arr == NULL || arr[0] == 0)
		return (-1);
	sqoute_start = ft_find_after_chr(arr, start, '\'');
	dqoute_start = ft_find_after_chr(arr, start, '\"');
	if (arr[sqoute_start] != 0)
		sqoute_end = ft_find_after_chr(arr, sqoute_start + 1, '\'');
	if (arr[dqoute_start] != 0)
		dqoute_end = ft_find_after_chr(arr, dqoute_start + 1, '\"');
	if ((arr[sqoute_start] == 0 || arr[sqoute_end] == 0) \
		&& (arr[dqoute_start] == 0 || arr[dqoute_end] == 0))
		return (0);
	else if (arr[sqoute_start] == 0 || arr[sqoute_end] == 0)
		return ('\"');
	else if (arr[dqoute_start] == 0 || arr[dqoute_end] == 0)
		return ('\'');
	if (sqoute_start > dqoute_start)
		return ('\"');
	else
		return ('\'');
}
