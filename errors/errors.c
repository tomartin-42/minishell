/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:01:25 by davyd11           #+#    #+#             */
/*   Updated: 2021/11/11 21:30:44 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errorlib.h"

int	error_unset_no_arg(void)
{
	ft_putstr_fd("unset: ", 2);
	ft_putstr_fd("not enough arguments", 2);
	ft_putstr_fd("\n", 2);
	g_state = 1;
	return (g_state);
}

int	error_unset_invalid_param(char *str)
{
	ft_putstr_fd("unset: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("invalid parameter name", 2);
	ft_putstr_fd("\n", 2);
	g_state = 1;
	return (g_state);
}

int	error_export_number(char *str)
{
	ft_putstr_fd("export: ", 2);
	ft_putstr_fd("not an identifier: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	g_state = 1;
	return (g_state);
}
