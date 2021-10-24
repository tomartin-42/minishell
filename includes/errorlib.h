/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:44:32 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/24 17:01:42 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORLIB_H
# define ERRORLIB_H

# include "minishell.h"

int	error_unset_no_arg(void);
int	error_unset_invalid_param(char *str);

#endif
