/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:05:57 by segan             #+#    #+#             */
/*   Updated: 2023/01/09 18:38:54 by segan            ###   ########.fr       */
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
	t_node_inf	*node_inf;
	char		***command;

	while (1)
	{
		node_inf = parsing(readline("minishell $ "));
		if (node_inf == EMPTY_LINE)
			continue ;
		// print_node(node_inf);	// print_test
		command = node_to_command(node_inf);
		// print_command(command);	// print_test
		execute_command(path_env, command, node_inf);
		ft_free_3d(command);
		ft_free(node_inf);
	}
}

int	main(void)
{
	control_process(get_path_env());
}
