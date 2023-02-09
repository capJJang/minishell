/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segan <segan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:12:54 by segan             #+#    #+#             */
/*   Updated: 2023/02/09 19:44:12 by segan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//void	sigint_readline()
//{
//	rl_replace_line("", 0);
//	printf("\n");
//	rl_on_new_line();
//	rl_redisplay();
//}

void	sigint_readline()
{
	struct termios	term;

	if (isatty(STDIN_FILENO))
	{
		tcgetattr(STDIN_FILENO, &term);
		term.c_lflag &= ~ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

void	sigint_child()
{
	struct termios	term;

	if (isatty(STDIN_FILENO))
	{
		tcgetattr(STDIN_FILENO, &term);
		term.c_lflag &= ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
		//rl_replace_line("", 0);
		//printf("\n");
		//rl_on_new_line();
		//rl_redisplay();
	}
	printf("\n");
}

void	sigquit_child()
{
	struct termios	term;

	if (isatty(STDIN_FILENO))
	{
		tcgetattr(STDIN_FILENO, &term);
		term.c_lflag &= ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
		//rl_replace_line("", 0);
		//printf("\n");
		//rl_on_new_line();
		//rl_redisplay();
	}
	printf("QUIT : %d\n", SIGQUIT);
}

void	init_signal()
{
	signal(SIGINT, sigint_readline);
	signal(SIGQUIT, SIG_IGN);
}

void	restore_signal()
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	set_child_signal()
{
	signal(SIGINT, sigint_child);
	signal(SIGQUIT, sigquit_child);
}

void	set_parent_signal()
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

//void	set_signal_heredoc(pid_t pid)
//{
//	if (pid == 0)
//		interactive_signal();
//	else
//		set_parent_signal();
//}

//void	set_signal_

/*
부모는 sigquit, sigint 무시
자식은 디폭트로 돌림
case : cat
	\ : ^\Quit :3		exit status : 131
	c : ^C				exit status : 130
	d :					exit status : 0

case : <<
	\ : (SIG_IGN)
	c : ^C				exit status : 1
	d :	(no newline)	exit status : 0

		자식	부모
isatty			시그널 무시
!isatty
*/
