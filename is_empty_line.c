/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:41:22 by seyang            #+#    #+#             */
/*   Updated: 2023/03/10 23:04:57 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_empty_line(char *read_line)
{
	int	ret;
	int	i;

	ret = 1;
	i = 0;
	if (read_line == EMPTY_LINE)
	{
		free(readline("exit"));
		// write(STDIN_FILENO, "\n", 1);
		printf("exit\n");
		exit(0);
	}
	if (read_line[0] == 0)
	{
		free(read_line);
		return (1);
	}
	add_history(read_line);
	while (read_line[i])
	{
		if (read_line[i] != ' ' && read_line[i] != '\t')
			ret = 0;
		i++;
	}
	if (ret)
		free(read_line);
	return (ret);
}
