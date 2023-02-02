/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:05:57 by segan             #+#    #+#             */
/*   Updated: 2023/02/02 17:44:40 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// struct termios	default_term;

// void	sig_handle(signum)
// {
// 	if (signum == SIGINT)
// 		readline("minishell $ ");
// }

// void	set_signal(void)
// {
// 	signal(SIGINT, sig_handle);
// }

// void	save_termios(void)
// {
// 	tcgetattr(STDIN_FILENO, &default_term);
// }

// void	reset_termios(void)
// {
// 	tcsetattr(STDIN_FILENO, TCSANOW, &default_term);
// }

// void	init_termios(void)
// {
// 	struct termios	new_term;

// 	tcgetattr(STDIN_FILENO, &new_term);
// 	// new_term.c_lflag &= ~(ICANON);
// 	new_term.c_lflag &= ~(ICANON | ECHO);
// 	new_term.c_cc[VMIN] = 1;
// 	new_term.c_cc[VTIME] = 0;
// 	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
// }

// char	*check_signal(void)
// {
// 	// int ch = 0;
// 	save_termios();
// 	init_termios();
// 	char *test = readline("minishell $ ");
// 	if (test == NULL)
// 	{
// 		reset_termios();
// 		printf("\n");
// 	}
// 	else
// 	{
// 		reset_termios();
// 		return (test);
// 	}
// 	reset_termios();
// 	return ((char *)CONTINUE);
// }

void	control_process(t_vars *vars)
{
	t_node_inf	*node_inf;
	char		*input;
	char		***cmd;

	// save_termios();
	// set_signal();
	while (1)
	{
		input = readline("minishell $ ");
		if (input == EMPTY_LINE)
		{
			printf("\b\bexit\n");
			exit(0);
		}
		if (is_empty_line(input))
			continue ;
		node_inf = parsing(input);
		if (check_parse_error(node_inf) == 1)
		{
			// temp
			printf("%s", "bash: syntax error near unexpected token `newline'\n");
			continue ;
		}
		// print_node(node_inf);	// print_test
		cmd = node_to_command(node_inf);
		// print_command(cmd);	// print_test
		node_inf->vars = vars;
		execute_command(get_path_env(vars->env), cmd, node_inf);
		ft_free_3d(cmd);
		ft_free(node_inf);
	}
}

int	main(void)
{
	t_vars	*vars;

	init_signal();
	vars = init_var();
	control_process(vars);
	ft_free_vars(vars);
}
