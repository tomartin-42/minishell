/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:44:32 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/28 10:47:59 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORLIB_H
# define ERRORLIB_H

# include "minishell.h"

int	main_error(char *line);
int check_fault_marks(char *line);
int	error_unset_no_arg(void);
int	error_unset_invalid_param(char *str);
int	error_export_number(char *str);
int	error_cmd_not_found(char *str);
int	error_open_marks(void);
int	error_undef_redir(void);
int	check_undefined_redir(char *str);

#endif
