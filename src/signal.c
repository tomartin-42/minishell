/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:14:23 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/01 10:16:05 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_proces(int sig)
{
	(void)sig;
	write(2, "\n", 1);
	//rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
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
