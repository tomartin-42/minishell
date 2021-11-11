/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:44:32 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/11 13:13:12 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORLIB_H
# define ERRORLIB_H

# include "minishell.h"

int	main_error(char *line);
int	check_fault_marks(char *line);
int	error_unset_no_arg(void);
int	error_unset_invalid_param(char *str);
int	error_export_number(char *str);
int	error_cmd_not_found(char *str);
int	error_open_marks(void);
int	error_undef_redir(void);
int	error_forbidden_char(void);
int	check_undefined_redir(char *str);
int	check_forbidden_chars(char *str);

#endif
