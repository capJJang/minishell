/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:05:57 by segan             #+#    #+#             */
/*   Updated: 2022/12/12 16:54:12 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	execute_command(char **command, char **path_env)
// {
// 	int		ret;
// 	int		i;
// 	char	*path;
// 	pid_t	pid;
	
// 	i = 0;
// 	while (1)
// 	{
// 		path = get_path(path_env[i++], command[0]);
// 		pid = ft_fork();
// 		if (pid == 0)
// 			is_child(path, command);
// 		else
// 			ret = is_parent(pid, path_env[i], command[0]);
// 		if (ret == IS_NOT_COMMAND)
// 			continue ;
// 		break ;
// 	}
// 	return (ret);
// }

void	control_process(char **path_env)
{
	//char		**command;
    t_node_inf  *node_inf;

	(void) path_env;
	while (1)
	{
		node_inf = parsing(readline("minishell $ "));
		// node_to_command(node_inf);
		// excute_command();
	}

}

int	main(void)
{
	control_process(get_path_env());
}
