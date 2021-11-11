/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:14:23 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/11 14:03:34 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Ctrl + C
/* static void	exit_proces(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
} */

void	select_signal(void)
{
	signal(SIGINT, &exit_proces);
	signal(SIGQUIT, SIG_IGN);
}

/*void	exit_in_proces(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 0);
}*/

/*static void	quit_in_proces(int sig)
{
	(void)sig;
	printf("HOLA\n");
	write(2, "Quit\n", 5);
	//signal(SIGQUIT, SIG_DFL);
}*/	

void	signal_in_proces(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

/*static void	exit_in_hered(int sig)
{
	(void)sig;
	g_state = 130;
	exit (130);
}*/

/*static void	quit_in_hered(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}*/

void	signal_hered(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

/*static void	exit_build_hered(int sig)
{
	(void)sig;
	rl_replace_line("\03", 0);
	rl_on_new_line();
	rl_redisplay();
	g_state = 130;
}*/

void	signal_build_hered(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_ignorate(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
