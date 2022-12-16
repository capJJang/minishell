/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_after_chr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:53:49 by seyang            #+#    #+#             */
/*   Updated: 2022/12/16 17:56:49 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_find_after_chr(char *arr, int start, char c)
{
	int	i;

	i = start;
	if (arr == NULL || arr[0] == 0)
		return (-1);	//20221215 segan : can cause segfault!, case : echo "test"
						//20221216 seyang : add arr[0] == 0 & in parsing_command, parsing_quote, set_single_or_double
	while (*arr)
	{
		if (arr[i] == c || arr[i] == 0)
			return (i);
		i++;
	}
	return (-1);
}
