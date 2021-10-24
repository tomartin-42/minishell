/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:14:23 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/24 13:03:29 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_proces(int sig)
{
	(void)sig;
	write(2, "\n\n", 2);
	//rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	quit_proces(int sig)
{
	(void)sig;
}


void	select_signal(void)
{
	signal(SIGINT, &exit_proces);
	signal(SIGQUIT, &quit_proces);
}

