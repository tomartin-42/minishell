/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:44:32 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/24 18:57:02 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORLIB_H
# define ERRORLIB_H

# include "minishell.h"

int	error_unset_no_arg(void);
int	error_unset_invalid_param(char *str);
int	error_export_number(char *str);

#endif