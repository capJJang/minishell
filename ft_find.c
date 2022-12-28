/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:53:49 by seyang            #+#    #+#             */
/*   Updated: 2022/12/26 19:30:27 by seyang           ###   ########.fr       */
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

int	ft_find_redirection(char *arr, int start)
{
	int	left;
	int	right;

	left = start;
	while (arr[left])
	{
		if (arr[left] == '<')
			break ;
		left++;
	}
	right = start;
	while (arr[right])
	{
		if (arr[right] == '>')
			break ;
		right++;
	}
	if (left > right)
		return (right);
	else
		return (left);
}