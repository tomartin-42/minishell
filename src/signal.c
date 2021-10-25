/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:14:23 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/25 10:23:03 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_proces(int sig)
{
	(void)sig;
	write(2, "\n\n", 2);
	//rl_replace_line("", 0);
	rl_line_buffer[0] = '\0';
	rl_point = 0;
	rl_end = 0;
	rl_on_new_line();
	rl_redisplay();
	write(1, "🔥ShellFromHell🔥: > ", 25);
}

static void	quit_proces(int sig)
{
	(void)sig;
	write(2, "Quit\n", 5);
}

void	select_signal(void)
{
	signal(SIGINT, &exit_proces);
	signal(SIGQUIT, &quit_proces);
}

