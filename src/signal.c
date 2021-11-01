/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:14:23 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/01 18:52:12 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Ctrl + C
static void	exit_proces(int sig)
{
	(void)sig;
	//printf("SIGINIT\n");
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

//Ctrl + barra 
static void	quit_proces(int sig)
{
	(void)sig;
	printf("SIGQUIT\n");
	write(2, "\n", 1);
	write(2, "Quit\n", 5);
}

void	select_signal(void)
{
	signal(SIGINT, &exit_proces);
	signal(SIGQUIT, &quit_proces);
}

void	exit_in_proces(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 0);
}

void	signal_in_proces(void)
{
	signal(SIGINT, &exit_in_proces);
}

static void	exit_in_hered(int sig)
{
	(void)sig;
	g_state = 130;
	exit (130);
}

void	signal_hered(void)
{
	signal(SIGINT, &exit_in_hered); 
}
