/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyang <seyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:11:07 by seyang            #+#    #+#             */
/*   Updated: 2022/12/12 19:11:09 by seyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_readline(void)
{
	char	*str;
	char	**command;

	str = readline("minishell $ ");
	command = ft_split(str, ' ');
	free(str);
	return (command);
}