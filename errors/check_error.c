/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:22:59 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/29 17:48:31 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "errorlib.h"

int	check_fault_marks(char *str)
{
	t_mark	chk;
	int		err;

	err = 0;
	ini_var(&chk);
	while (str[chk.i])
	{
		check_open_mark(str, &chk.mark_s, &chk.mark_d, &chk.i);
		chk.i++;
		check_close_mark(str, &chk.mark_s, &chk.mark_d, &chk.i);
	}
	if (chk.mark_s == true || chk.mark_d == true)
	{
		g_state = error_open_marks();
		err = 1;
	}
	return (err);
}
