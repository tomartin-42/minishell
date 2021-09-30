/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:22:59 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/27 20:37:00 by davyd11          ###   ########.fr       */
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
		//free(str);
		return (-1);
	}
	return (0);
}

