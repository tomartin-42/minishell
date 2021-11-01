/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:52:27 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/01 14:15:14 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errorlib.h"

int	main_error(char *line)
{
	if (check_fault_marks(line))
		return (1);
	if (check_undefined_redir(line))
	{
		error_undef_redir();
		return (1);
	}
	if (!check_forbidden_chars(line))
	{
		error_forbidden_char();
		return (1);
	}
	return (0);
}
