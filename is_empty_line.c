/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:41:22 by seyang            #+#    #+#             */
/*   Updated: 2023/01/31 23:07:49 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_empty_line(char *read_line)
{
	int	ret;
	int	i;

	ret = 1;
	i = 0;
	if (read_line[0] == 0)
	{
		free(read_line);
		return (1);
	}
	while (read_line[i])
	{
		if (read_line[i] != ' ')
			ret = 0;
		i++;
	}
	if (ret)
		free(read_line);
	return (ret);
}
