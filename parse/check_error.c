/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:22:59 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/26 17:49:57 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_fault_marks(char *str)
{
	t_mark	chk;

	ini_var(&chk);
	while(str[chk.i])
	{
		check_open_mark(str, &chk.mark_s, &chk.mark_d, &chk.i);
		chk.i++;
		check_close_mark(str, &chk.mark_s, &chk.mark_d, &chk.i);
	}
	if (chk.mark_s == true || chk.mark_d == true)
	{
		printf("ERROR comillas abiertas\n");
		return (-1);
	}
	return (0);
}

