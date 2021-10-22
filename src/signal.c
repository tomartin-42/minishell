/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:14:23 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/20 11:10:08 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_proces(int sig)
{
	printf("SEÑAL SISGINT %d\n", sig);
}

static void	quit_proces(int sig)
{
	printf("SEÑAL SISQUIT %d\n", sig);
}

void	select_signal(void)
{
	signal(SIGINT, &exit_proces);
	signal(SIGQUIT, &quit_proces);
}

