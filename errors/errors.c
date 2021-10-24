/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:01:25 by davyd11           #+#    #+#             */
/*   Updated: 2021/10/24 17:03:07 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errorlib.h"

int	error_unset_no_arg(void)
{
		ft_putstr_fd("unset: ", 2);
		ft_putstr_fd("not enough arguments", 2);
		ft_putstr_fd("\n", 2);	
		return (1);
}

int	error_unset_invalid_param(char *str)
{
		ft_putstr_fd("unset: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("invalid parameter name", 2);
		ft_putstr_fd("\n", 2);	
		return (1);
}

