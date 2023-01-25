/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:11:07 by seyang            #+#    #+#             */
/*   Updated: 2023/01/25 19:23:33 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_readline(void)
{
	char	*str;
	char	**cmd;

	str = readline("minishell $ ");
	cmd = ft_split(str, ' ');
	free(str);
	return (cmd);
}
